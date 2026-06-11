#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 7600000000LL;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        ll a, b, ans = 0; scanf("%lld%lld", &a, &b);
        if(a==b) ans = 2*a-2;
        else{
            ll sq = sqrt(a*b);
            if(sq*sq == a*b) sq--;
            if(sq*(sq+1) >= a*b) ans = 2*sq-2;
            else ans = 2*sq-1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
