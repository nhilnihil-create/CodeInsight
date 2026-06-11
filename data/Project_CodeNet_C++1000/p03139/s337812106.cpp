#include <stdio.h>

int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int max;
    int min;
    if(a>b) max=b;
    else max=a;
    if(a+b>=n) min=a+b-n;
    else min=0;
    printf("%d %d\n",max,min);
}