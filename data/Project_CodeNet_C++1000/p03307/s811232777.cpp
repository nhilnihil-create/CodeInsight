#include <stdio.h>
int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a%2 == 0){
        printf("%d", a);
    }else{
        printf("%d", a * 2);
    }     
    
    return 0;
}
