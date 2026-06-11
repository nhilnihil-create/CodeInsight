#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<vector<ll>> dp(100,vector<ll>(2,-1));
    // dp[i][smaller]:上からi桁使う
    dp[0][0]=0;
    for(ll digit=0; digit<50; digit++){
        ll mask=(1LL<<(49-digit));
        ll num=0; //この桁が立っている数
        rep(i,n) if(a[i] & mask) num++;
        ll score0=num*mask;
        ll score1=(n-num)*mask;
        if(dp[digit][1]!=-1) chmax(dp[digit+1][1],dp[digit][1]+max(score0,score1));
        if(dp[digit][0]!=-1){
            if(k & mask) chmax(dp[digit+1][1],dp[digit][0]+score0);
        }
        if(dp[digit][0]!=-1){
            if(k & mask) chmax(dp[digit+1][0],dp[digit][0]+score1);
            else chmax(dp[digit+1][0],dp[digit][0]+score0);
        }
    }
    cout<<max(dp[50][0],dp[50][1])<<endl;
    return 0;
}