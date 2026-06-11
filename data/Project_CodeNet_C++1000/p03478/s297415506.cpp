#include <stdio.h>
int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int sum = 0;
    for(int i = 1;i <= n; i++){
        int num = i;
        int temp = 0;
        while(num > 0){
            temp += num % 10;
            num /= 10;
}
        if(temp >= a && temp <= b){
        sum += i;
        }
 
    }
    printf("%d", sum);
    return 0;}