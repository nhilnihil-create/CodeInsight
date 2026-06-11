#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll bsqrt(ll x){
    ll lo = 1, hi = 1e9;
    while(lo<hi){
        ll mid = (lo+hi)/2+1;
        if(mid*mid < x) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main(){
    int Q; scanf("%d",&Q);
    while(Q--){
        ll a, b; scanf("%lld%lld", &a,&b);
        if(a>b) swap(a,b);

        if(a==b){
            printf("%lld\n", 2*(a-1));
            continue;
        }

        ll ans = a-1;
        ll s = bsqrt(a*b);

        if(s*(s+1) >= a*b) {
            if(s <= a){
                ans += s-1;
            }
            else{
                if(s-a < b-s){
                    ans += s-1 + s-a;
                }
                else{
                    ans += b-1;
                }
            }
        }
        else {
            if(s+1 <= a){
                ans += s;
            }
            else{
                if(s+1-a < b-s){
                    ans += s + s-a;
                }
                else{
                    ans += b-1;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
