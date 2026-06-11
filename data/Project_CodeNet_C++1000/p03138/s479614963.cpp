#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 1e5+7;
ll s[maxn],sum[65];
int mx;
ll K[65];
ll dp[65][2][2];
void getS(ll num){
    int i=0;
    while(num){
        if(num & 1) sum[i]++;
        ++i;
        num >>= 1;
    }
    mx = max(mx,i-1);
}
int main() {
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&s[i]);
        getS(s[i]);
    }
    int p=0;
    while(k){
        if(k & 1) K[p]++;
        ++p;
        k >>= 1;
    }
    if(p==0){
        ll ans=0;
        for(int i=1;i<=n;++i){
            ans += s[i];
        }
        printf("%lld\n",ans);
        return 0;
    }
    p-=1;
    mx = max(p,mx);
    dp[p][1][0] = (n*1ll-sum[p])*(1ll << p);
    dp[p][0][1] = sum[p]*(1ll << p);
    ll temp;
    for(ll i=p - 1;i>=0;--i){
        ll b = (n*1ll-sum[i])*(1ll << i);//1
        ll a = sum[i]*(1ll << i);//0
        if(K[i] == 1){
            temp = max(dp[i+1][0][0],dp[i+1][1][0]);
            if(temp>0) {
                dp[i][1][0] = temp + b;
            }
           temp = max(dp[i+1][0][1],dp[i+1][1][1]);
           if(temp>0){
               dp[i][1][1] = temp + b;
           }
           temp = max(max(dp[i+1][0][0],dp[i+1][0][1]),max(dp[i+1][1][1],dp[i+1][1][0]));
            if(temp>0){
                dp[i][0][1] = temp + a;
            }
        }else if(K[i] == 0){
            temp =  max(dp[i+1][0][0],dp[i+1][1][0]);
            if(temp>0){
                dp[i][0][0] = temp + a;
            }
           temp = max(dp[i+1][0][1],dp[i+1][1][1]);
           if(temp>0){
               dp[i][1][1] =  temp + b;
           }
            temp = max(dp[i+1][1][1],dp[i+1][0][1]);
           if(temp > 0){
               dp[i][0][1] = temp + a;
           }
        }

    }
    ll ans = max(max(dp[0][1][0],dp[0][1][1]),max(dp[0][0][1],dp[0][0][0]));
    for(ll i=mx;i>p;--i){
        ans += sum[i]*(1ll<<i);
    }
    printf("%lld\n",ans);
    return 0;
}