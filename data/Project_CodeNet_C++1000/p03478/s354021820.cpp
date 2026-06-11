#include <stdio.h>

#define ll long long int

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(i >= 10){
            int temp = i, sum = 0;
            while(temp > 0){
                sum += temp%10;
                temp /= 10;
            }
            if(sum >= a && sum <= b){
                ans += i;
            }
        }else{
            if(i >= a && i <= b){
                ans += i;
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
