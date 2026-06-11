#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

pll dp[(1LL<<18)+5][20];

ll res[4];
pll change(pll l,pll r){
    res[0]=l.first;
    res[1]=l.second;
    res[2]=r.first;
    res[3]=r.second;
    sort(res,res+4);
    return pll(res[3],res[2]);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(1<<n);
    rep(i,1<<n) scanf("%lld",&a[i]);
    rep(i,1<<n){
        dp[i][0].first = a[i];
        dp[i][0].second = -1;
    }
    rep(i,1<<n){
        for(int j=1;j<=n;j++){
            if(i>>(j-1)&1){
                dp[i][j] = change(dp[i][j-1],dp[i^(1<<(j-1))][j-1]);
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<(1<<n);i++){
        ans = max(ans,dp[i][n].first+dp[i][n].second);
        printf("%lld\n",ans);
    }
    return 0;
}