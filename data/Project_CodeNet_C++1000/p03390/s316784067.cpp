#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long a, b;
        scanf("%lld%lld",&a,&b);
        long long ua = min(a-1, (a*b-1)/(b+1));
        long long ub = min(b-1, (a*b-1)/(a+1));
        long long ans = 0;
        long long ss = 0, ee = 1100000000, sq = -1;
        while(ss <= ee){
            long long mid = (ss + ee) / 2;
            if(mid * mid <= (a * b - 1)){
                sq = mid;
                ss = mid + 1;
            }else{
                ee = mid - 1;
            }
        }
        if(ua <= sq){
            ans += ua;
        }else{
            ans += sq + min(max(((a*b-1) / (sq+1)) - b, 0LL), ua - sq);
        }
        if(ub <= sq){
            ans += ub;
        }else{
            ans += sq + min(max(((a*b-1) / (sq+1)) - a, 0LL), ub - sq);
        }
        printf("%lld\n", ans);
    }
}
