#include<stdio.h>

int main(){
    int n, a, b, ii, temp=0;
    long long int sum=0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i=1 ; i<=n ; i++){
        ii=i;
        temp=0;
        while(ii>0){
            temp+=ii%10;
            ii/=10;
        }
        if(temp>=a && temp<=b){
            sum+=i;
        }
    }
    printf("%lld\n", sum);
    return 0;
}