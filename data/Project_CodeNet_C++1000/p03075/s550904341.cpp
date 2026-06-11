#include<stdio.h>
#include<stdlib.h>

int main(){
	int Vetor[10];
	
	
	for(int i = 0; i <6;i++){
		
		scanf("%d",&Vetor[i]);
	}
	int Maior = Vetor[0];
	int Minimo = Vetor[0];
	for(int i = 0; i <5;i++){
			
			if(Vetor[i] >= Maior ){
				Maior= Vetor[i];
			}
			if(Vetor[i] <= Minimo ){
				Minimo= Vetor[i];
			}
			
		
		
	}

	int Soma;
	Soma= Maior-Minimo;
	if(Soma <= Vetor[5])
	{
		printf("Yay!\n");
	}
	else
	{
		printf(":(\n");
	}
	
	
	return 0;
}