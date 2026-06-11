#include <stdio.h>
int main(){
    int a, b, sum, dif, mult;
    int maior;
    
    scanf("%d %d", &a, &b);
    
    sum=a+b;
    dif=a-b;
    mult=a*b;
    maior=sum;
    
    if(dif>maior)
        maior=dif;
        
    if(mult>maior)
        maior=mult;
    
    printf("%d\n", maior);
    
    return 0;
}