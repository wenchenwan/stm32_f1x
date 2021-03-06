/*-------------------------------------------------------------------------------
文件名称：main.c
文件描述：普通延时控制LED2闪烁，间隔250ms，定时器控制LED3闪烁，间隔500ms。
          定时器可以更换为其他定时器，可以用字符替换方式更新。如TIM2替换成TIM3
硬件平台：尼莫M3S开发板
编写整理：shifang
固件库  ：V3.5
技术论坛：www.doflye.net
备    注：通过简单修改可以移植到其他开发板，部分资料来源于网络。
---------------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "timer.h"

int main(void)
{
	
	LED_Init();//LED初始化
  KEY_Init();//按键初始化
  SysTick_Init();//延时初始化
	TIM2_Base_Init(5000);//10Khz的计数频率，计数到5000为500ms  
  while(1)
	{
		Delay_ms(250);		  
		LED2_REV;		
	}
}

void TIM2_IRQHandler(void)   //TIM2中断
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
		{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
			
		LED3_REV; //取反LED3
		}
}

/*----------------------德飞莱 技术论坛：www.doflye.net--------------------------*/
