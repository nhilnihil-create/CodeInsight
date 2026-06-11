#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin>>a[i][j];

    vector<vector<ll>> dp(25,vector<ll>(1<<n,0));
    dp[0][0]=1;

    rep(i,n){//i番目の男性まで組を作っている
        rep(j,(1<<n)){//すでに組んでいる女性をbitで表現
            if(dp[i][j]==0) continue;
            rep(k,n){
                if(!((j>>k)&1) && a[i][k]){
                    dp[i+1][j|(1<<k)]+=dp[i][j];
                    dp[i+1][j|(1<<k)]%=mod;
                }
            }
        }
    }

    cout<<dp[n][(1<<n)-1]<<endl;
    return 0;
}