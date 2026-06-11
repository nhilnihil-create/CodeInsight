#include<bits/stdc++.h>
using namespace std;
const int N = 501;
const int mod = 1e9 + 7;
int main(){
    long long n, p;
    long long ans = 1;
    scanf("%lld %lld", &n, &p);
    for(int i = 2; 1LL * i * i <= p; i++){
        if(p % i) continue;
        int cnt = 0;
        while(p % i == 0){
            p /= i;
            cnt++;
            if(cnt == n){
                ans *= i;
                cnt = 0;
            }
        }
    }
    if(p > 1 && n == 1){
        ans *= p;
    }
    printf("%lld\n", ans);
    return 0;
}