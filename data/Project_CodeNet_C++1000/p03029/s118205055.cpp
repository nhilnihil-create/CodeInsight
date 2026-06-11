#include<stdio.h>
#include<math.h>

int main(){
    
    int a,b;
    scanf("%d %d", &a, &b);
    int sum = a * 3 + b;
    
    printf("%.lf\n", floor((float) sum / 2.0));
    
    return 0;
}