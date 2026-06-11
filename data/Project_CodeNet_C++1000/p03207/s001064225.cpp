#include<stdio.h> 
int main(){ 
    int n,i,max,a,x,sum=0,fsum;
    scanf("%d",&n);
    for(i=0,a=0,max=a;i<n;i++){
        scanf("%d",&x);
        sum+=x;
        if(x>max){
            max=x;
            
        }
        
    }
    fsum=sum-(max/2);
    printf("%d",fsum);
    
    
    
     return 0; 
    }