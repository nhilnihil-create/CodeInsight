#include <bits/stdc++.h>
#define N 100005
typedef long long ll; 
using namespace std;
ll k,a[N],best;
ll check(ll x)
{
    for(ll i=1;i<=k;i++){
        if(x<a[i])return -1;
        x-=x%a[i];
    }return x;
}
int main()
{
    scanf("%lld",&k);
    for(ll i=1;i<=k;i++)scanf("%lld",&a[i]);
    best=-1;ll l=0,r=1000000000000000000LL;
    while(l<=r){
        ll mid=(l+r)>>1LL;
        if(check(mid)==-1)l=mid+1;else r=mid-1;
        if(check(mid)==2)best=mid;
    }printf("%lld ",best);if(best==-1){return 0;}
    l=0,r=1000000000000000000LL;best=-1;
    while(l<=r){
        ll mid=(l+r)>>1LL;
        if(check(mid)==-1||check(mid)<=2)l=mid+1;else r=mid-1;
        if(check(mid)==2)best=mid;
    }printf("%lld",best);if(best==-1){return 0;}
    return 0;
}