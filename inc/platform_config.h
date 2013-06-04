/**
 ******************************************************************************
 * @file    platform_config.h
 * @author  Spark Application Team
 * @version V1.0.0
 * @date    03-June-2013
 * @brief   Board specific configuration file.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Uncomment the line corresponding to the STM32 board used */
#if !defined (USE_SPARK_CORE) &&  !defined (USE_OLIMEX_H103) &&  !defined (USE_ST_VLDISCOVERY)
#define USE_SPARK_CORE
//#define USE_OLIMEX_H103
//#define USE_ST_VLDISCOVERY
#endif

/* Uncomment the line below to enable DFU based build and follow the below step*/
/* In Eclipse Project Properties -> C/C++ Build -> Settings -> Tool Settings
 * -> ARM Sourcery Windows GCC C Linker -> General -> Script file (-T),
 * Browse & select linker file : "linker_stm32f10x_md_dfu.ld"
 */
//#define DFU_BUILD_ENABLE

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Define the STM32F10x hardware depending on the used board */
#if defined (USE_SPARK_CORE)

//LEDs
#define LEDn                           		2
#define LED1_PIN                         	GPIO_Pin_8
#define LED1_GPIO_PORT                   	GPIOA
#define LED1_GPIO_CLK                    	RCC_APB2Periph_GPIOA
#define LED2_PIN                         	GPIO_Pin_9
#define LED2_GPIO_PORT                   	GPIOA
#define LED2_GPIO_CLK                    	RCC_APB2Periph_GPIOA

//Push Buttons
#define BUTTONn                           	2
#define BUTTON1_PIN                      	GPIO_Pin_10
#define BUTTON1_GPIO_PORT                	GPIOA
#define BUTTON1_GPIO_CLK                 	RCC_APB2Periph_GPIOA
#define BUTTON1_GPIO_MODE					GPIO_Mode_IPU
#define BUTTON1_PRESSED						0x00
#define BUTTON1_EXTI_LINE                	EXTI_Line10
#define BUTTON1_EXTI_PORT_SOURCE         	GPIO_PortSourceGPIOA
#define BUTTON1_EXTI_PIN_SOURCE          	GPIO_PinSource10
#define BUTTON1_EXTI_IRQn                	EXTI15_10_IRQn
#define	BUTTON1_EXTI_TRIGGER				EXTI_Trigger_Falling
#define BUTTON2_PIN                     	0//GPIO_Pin_y
#define BUTTON2_GPIO_PORT               	0//GPIOY
#define BUTTON2_GPIO_CLK                	0//RCC_APB2Periph_GPIOY
#define BUTTON2_GPIO_MODE					0//GPIO_Mode_IN_FLOATING
#define BUTTON2_PRESSED						0//0x00
#define BUTTON2_EXTI_LINE               	0//EXTI_Liney
#define BUTTON2_EXTI_PORT_SOURCE        	0//GPIO_PortSourceGPIOY
#define BUTTON2_EXTI_PIN_SOURCE         	0//GPIO_PinSourcey
#define BUTTON2_EXTI_IRQn               	0//EXTIy_IRQn
#define	BUTTON2_EXTI_TRIGGER				0//EXTI_Trigger_Falling

//Button Debounce Timer
#define DEBOUNCE_FREQ						100	//100 Hz => 10ms
#define DEBOUNCE_TIMER						TIM1
#define DEBOUNCE_TIMER_CLK					RCC_APB2Periph_TIM1
#define DEBOUNCE_TIMER_CLK_CMD				RCC_APB2PeriphClockCmd
#define DEBOUNCE_TIMER_FLAG            		TIM_IT_Update
#define DEBOUNCE_TIMER_IRQn           		TIM1_UP_IRQn

//CC3000 Interface pins
#define CC3000_SPI							SPI2
#define CC3000_SPI_CLK						RCC_APB1Periph_SPI2
#define CC3000_SPI_CLK_CMD					RCC_APB1PeriphClockCmd
#define CC3000_SPI_SCK_PIN					GPIO_Pin_13					/* PB.13 */
#define CC3000_SPI_SCK_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_SCK_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_SPI_MISO_PIN					GPIO_Pin_14					/* PB.14 */
#define CC3000_SPI_MISO_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_MISO_GPIO_CLK			RCC_APB2Periph_GPIOB
#define CC3000_SPI_MOSI_PIN					GPIO_Pin_15					/* PB.15 */
#define CC3000_SPI_MOSI_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_MOSI_GPIO_CLK			RCC_APB2Periph_GPIOB
#define CC3000_WIFI_CS_PIN					GPIO_Pin_12					/* PB.12 */
#define CC3000_WIFI_CS_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_CS_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_WIFI_EN_PIN					GPIO_Pin_8					/* PB.08 */
#define CC3000_WIFI_EN_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_EN_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_WIFI_INT_PIN					GPIO_Pin_11					/* PB.11 */
#define CC3000_WIFI_INT_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_INT_GPIO_CLK			RCC_APB2Periph_GPIOB

#define CC3000_WIFI_INT_EXTI_LINE           EXTI_Line11
#define CC3000_WIFI_INT_EXTI_PORT_SOURCE    GPIO_PortSourceGPIOB
#define CC3000_WIFI_INT_EXTI_PIN_SOURCE     GPIO_PinSource11
#define CC3000_WIFI_INT_EXTI_IRQn           EXTI15_10_IRQn

#define CC3000_SPI_DMA_CLK                  RCC_AHBPeriph_DMA1
#define CC3000_SPI_RX_DMA_CHANNEL           DMA1_Channel4
#define CC3000_SPI_TX_DMA_CHANNEL           DMA1_Channel5
#define CC3000_SPI_RX_DMA_TCFLAG            DMA1_FLAG_TC4
#define CC3000_SPI_TX_DMA_TCFLAG            DMA1_FLAG_TC5
#define CC3000_SPI_RX_DMA_IRQn           	DMA1_Channel4_IRQn
#define CC3000_SPI_TX_DMA_IRQn           	DMA1_Channel5_IRQn

#define CC3000_SPI_DR_BASE                  ((uint32_t)0x4000380C)	/* SPI2_BASE | 0x0C */

#define CC3000_SPI_BAUDRATE_PRESCALER		SPI_BaudRatePrescaler_32

#elif defined (USE_OLIMEX_H103)

//LEDs
#define LEDn                           		2
#define LED1_PIN                         	GPIO_Pin_12
#define LED1_GPIO_PORT                   	GPIOC
#define LED1_GPIO_CLK                    	RCC_APB2Periph_GPIOC
#define LED2_PIN                         	GPIO_Pin_5
#define LED2_GPIO_PORT                   	GPIOB
#define LED2_GPIO_CLK                    	RCC_APB2Periph_GPIOB

//Push Buttons
#define BUTTONn                           	2
#define BUTTON1_PIN                      	GPIO_Pin_0
#define BUTTON1_GPIO_PORT                	GPIOA
#define BUTTON1_GPIO_CLK                 	RCC_APB2Periph_GPIOA
#define BUTTON1_GPIO_MODE					GPIO_Mode_IN_FLOATING
#define BUTTON1_PRESSED						0x00
#define BUTTON1_EXTI_LINE                	EXTI_Line0
#define BUTTON1_EXTI_PORT_SOURCE         	GPIO_PortSourceGPIOA
#define BUTTON1_EXTI_PIN_SOURCE          	GPIO_PinSource0
#define BUTTON1_EXTI_IRQn                	EXTI0_IRQn
#define	BUTTON1_EXTI_TRIGGER				EXTI_Trigger_Falling
#define BUTTON2_PIN                     	0//GPIO_Pin_y
#define BUTTON2_GPIO_PORT               	0//GPIOY
#define BUTTON2_GPIO_CLK                	0//RCC_APB2Periph_GPIOY
#define BUTTON2_GPIO_MODE					0//GPIO_Mode_IN_FLOATING
#define BUTTON2_PRESSED						0//0x00
#define BUTTON2_EXTI_LINE               	0//EXTI_Liney
#define BUTTON2_EXTI_PORT_SOURCE        	0//GPIO_PortSourceGPIOY
#define BUTTON2_EXTI_PIN_SOURCE         	0//GPIO_PinSourcey
#define BUTTON2_EXTI_IRQn               	0//EXTIy_IRQn
#define	BUTTON2_EXTI_TRIGGER				0//EXTI_Trigger_Falling

//Button Debounce Timer
#define DEBOUNCE_FREQ						100	//100 Hz => 10ms
#define DEBOUNCE_TIMER						TIM1
#define DEBOUNCE_TIMER_CLK					RCC_APB2Periph_TIM1
#define DEBOUNCE_TIMER_CLK_CMD				RCC_APB2PeriphClockCmd
#define DEBOUNCE_TIMER_FLAG            		TIM_IT_Update
#define DEBOUNCE_TIMER_IRQn           		TIM1_UP_IRQn

//CC3000 Interface pins
#define CC3000_SPI							SPI1
#define CC3000_SPI_CLK						RCC_APB2Periph_SPI1
#define CC3000_SPI_CLK_CMD					RCC_APB2PeriphClockCmd
#define CC3000_SPI_SCK_PIN					GPIO_Pin_5                  /* PA.05 */
#define CC3000_SPI_SCK_GPIO_PORT			GPIOA                       /* GPIOA */
#define CC3000_SPI_SCK_GPIO_CLK				RCC_APB2Periph_GPIOA
#define CC3000_SPI_MISO_PIN					GPIO_Pin_6                  /* PA.06 */
#define CC3000_SPI_MISO_GPIO_PORT			GPIOA                       /* GPIOA */
#define CC3000_SPI_MISO_GPIO_CLK			RCC_APB2Periph_GPIOA
#define CC3000_SPI_MOSI_PIN					GPIO_Pin_7                  /* PA.07 */
#define CC3000_SPI_MOSI_GPIO_PORT			GPIOA                       /* GPIOA */
#define CC3000_SPI_MOSI_GPIO_CLK			RCC_APB2Periph_GPIOA
#define CC3000_WIFI_CS_PIN					GPIO_Pin_8          	    /* PA.08 */
#define CC3000_WIFI_CS_GPIO_PORT			GPIOA                       /* GPIOA */
#define CC3000_WIFI_CS_GPIO_CLK				RCC_APB2Periph_GPIOA
#define CC3000_WIFI_EN_PIN					GPIO_Pin_1	              	/* PB.01 */
#define CC3000_WIFI_EN_GPIO_PORT			GPIOB                       /* GPIOB */
#define CC3000_WIFI_EN_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_WIFI_INT_PIN					GPIO_Pin_0	             	/* PB.00 */
#define CC3000_WIFI_INT_GPIO_PORT			GPIOB                       /* GPIOB */
#define CC3000_WIFI_INT_GPIO_CLK			RCC_APB2Periph_GPIOB

#define CC3000_WIFI_INT_EXTI_LINE           EXTI_Line0
#define CC3000_WIFI_INT_EXTI_PORT_SOURCE    GPIO_PortSourceGPIOB
#define CC3000_WIFI_INT_EXTI_PIN_SOURCE     GPIO_PinSource0
#define CC3000_WIFI_INT_EXTI_IRQn           EXTI0_IRQn

#define CC3000_SPI_DMA_CLK                  RCC_AHBPeriph_DMA1
#define CC3000_SPI_RX_DMA_CHANNEL           DMA1_Channel2
#define CC3000_SPI_TX_DMA_CHANNEL           DMA1_Channel3
#define CC3000_SPI_RX_DMA_TCFLAG            DMA1_FLAG_TC2
#define CC3000_SPI_TX_DMA_TCFLAG            DMA1_FLAG_TC3
#define CC3000_SPI_RX_DMA_IRQn           	DMA1_Channel2_IRQn
#define CC3000_SPI_TX_DMA_IRQn           	DMA1_Channel3_IRQn

#define CC3000_SPI_DR_BASE                  ((uint32_t)0x4001300C)	/* SPI1_BASE | 0x0C */

#define CC3000_SPI_BAUDRATE_PRESCALER		SPI_BaudRatePrescaler_32

#elif defined (USE_ST_VLDISCOVERY)

//LEDs
#define LEDn                           		2
#define LED1_PIN                         	GPIO_Pin_8
#define LED1_GPIO_PORT                   	GPIOC
#define LED1_GPIO_CLK                    	RCC_APB2Periph_GPIOC
#define LED2_PIN                         	GPIO_Pin_9
#define LED2_GPIO_PORT                   	GPIOC
#define LED2_GPIO_CLK                    	RCC_APB2Periph_GPIOC

//Push Buttons
#define BUTTONn                           	2
#define BUTTON1_PIN                      	GPIO_Pin_0
#define BUTTON1_GPIO_PORT                	GPIOA
#define BUTTON1_GPIO_CLK                 	RCC_APB2Periph_GPIOA
#define BUTTON1_GPIO_MODE					GPIO_Mode_IN_FLOATING
#define BUTTON1_PRESSED						0x01
#define BUTTON1_EXTI_LINE                	EXTI_Line0
#define BUTTON1_EXTI_PORT_SOURCE         	GPIO_PortSourceGPIOA
#define BUTTON1_EXTI_PIN_SOURCE          	GPIO_PinSource0
#define BUTTON1_EXTI_IRQn                	EXTI0_IRQn
#define	BUTTON1_EXTI_TRIGGER				EXTI_Trigger_Rising
#define BUTTON2_PIN                     	0//GPIO_Pin_y
#define BUTTON2_GPIO_PORT               	0//GPIOY
#define BUTTON2_GPIO_CLK                	0//RCC_APB2Periph_GPIOY
#define BUTTON2_GPIO_MODE					0//GPIO_Mode_IN_FLOATING
#define BUTTON2_PRESSED						0//0x00
#define BUTTON2_EXTI_LINE               	0//EXTI_Liney
#define BUTTON2_EXTI_PORT_SOURCE        	0//GPIO_PortSourceGPIOY
#define BUTTON2_EXTI_PIN_SOURCE         	0//GPIO_PinSourcey
#define BUTTON2_EXTI_IRQn               	0//EXTIy_IRQn
#define	BUTTON2_EXTI_TRIGGER				0//EXTI_Trigger_Falling

//Button Debounce Timer
#define DEBOUNCE_FREQ						100	//100 Hz => 10ms
#define DEBOUNCE_TIMER						TIM1
#define DEBOUNCE_TIMER_CLK					RCC_APB2Periph_TIM1
#define DEBOUNCE_TIMER_CLK_CMD				RCC_APB2PeriphClockCmd
#define DEBOUNCE_TIMER_FLAG            		TIM_IT_Update
#define DEBOUNCE_TIMER_IRQn           		TIM1_UP_TIM16_IRQn

//CC3000 Interface pins
#define CC3000_SPI							SPI2
#define CC3000_SPI_CLK						RCC_APB1Periph_SPI2
#define CC3000_SPI_CLK_CMD					RCC_APB1PeriphClockCmd
#define CC3000_SPI_SCK_PIN					GPIO_Pin_13					/* PB.13 */
#define CC3000_SPI_SCK_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_SCK_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_SPI_MISO_PIN					GPIO_Pin_14					/* PB.14 */
#define CC3000_SPI_MISO_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_MISO_GPIO_CLK			RCC_APB2Periph_GPIOB
#define CC3000_SPI_MOSI_PIN					GPIO_Pin_15					/* PB.15 */
#define CC3000_SPI_MOSI_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_SPI_MOSI_GPIO_CLK			RCC_APB2Periph_GPIOB
#define CC3000_WIFI_CS_PIN					GPIO_Pin_12					/* PB.12 */
#define CC3000_WIFI_CS_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_CS_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_WIFI_EN_PIN					GPIO_Pin_8					/* PB.08 */
#define CC3000_WIFI_EN_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_EN_GPIO_CLK				RCC_APB2Periph_GPIOB
#define CC3000_WIFI_INT_PIN					GPIO_Pin_11					/* PB.11 */
#define CC3000_WIFI_INT_GPIO_PORT			GPIOB						/* GPIOB */
#define CC3000_WIFI_INT_GPIO_CLK			RCC_APB2Periph_GPIOB

#define CC3000_WIFI_INT_EXTI_LINE           EXTI_Line11
#define CC3000_WIFI_INT_EXTI_PORT_SOURCE    GPIO_PortSourceGPIOB
#define CC3000_WIFI_INT_EXTI_PIN_SOURCE     GPIO_PinSource11
#define CC3000_WIFI_INT_EXTI_IRQn           EXTI15_10_IRQn

#define CC3000_SPI_DMA_CLK                  RCC_AHBPeriph_DMA1
#define CC3000_SPI_RX_DMA_CHANNEL           DMA1_Channel4
#define CC3000_SPI_TX_DMA_CHANNEL           DMA1_Channel5
#define CC3000_SPI_RX_DMA_TCFLAG            DMA1_FLAG_TC4
#define CC3000_SPI_TX_DMA_TCFLAG            DMA1_FLAG_TC5
#define CC3000_SPI_RX_DMA_IRQn           	DMA1_Channel4_IRQn
#define CC3000_SPI_TX_DMA_IRQn           	DMA1_Channel5_IRQn

#define CC3000_SPI_DR_BASE                  ((uint32_t)0x4000380C)	/* SPI2_BASE | 0x0C */

#define CC3000_SPI_BAUDRATE_PRESCALER		SPI_BaudRatePrescaler_32

#endif

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */