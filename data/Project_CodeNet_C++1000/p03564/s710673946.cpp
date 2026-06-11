#include<stdio.h>
int main()
{
    int N;
    int K;
	
    scanf("%d",&N);   
    scanf("%d",&K);    
    
    int total = 1;   
	     
    for(int i = 0;i<N;i++){ 
        if(total < K){     
            total = total * 2; 
        }
        else{
            total = total + K;  
        }
    }
    printf("%d\n",total);
    return 0;
}