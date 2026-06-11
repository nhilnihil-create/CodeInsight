#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    rep(j,N) dp[0][j]=1;
    vector<ll> sum(N+1);
    rep(i,N-1){
        sum[0]=0;
        rep(j,N) sum[j+1]=(sum[j]+dp[i][j])%MOD;
        if (S[i]=='<') rep(j,N-i-1) dp[i+1][j]=(dp[i+1][j]+sum[N]-sum[j+1]+MOD)%MOD;
        else rep(j,N-i-1) dp[i+1][j]=(dp[i+1][j]+sum[j+1])%MOD;
    }
    cout << dp[N-1][0] << endl;
}