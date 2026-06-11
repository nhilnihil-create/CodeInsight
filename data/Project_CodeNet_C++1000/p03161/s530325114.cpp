#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,K; cin>>N>>K;
    vector<ll> h(N); rep(i,N)cin>>h[i];
    vector<ll> dp(N,INF);
    dp[0] = 0;
    rep(i,N){
        rep1(j,K){
            if(i+j<N)dp[i+j] = min(dp[i+j],dp[i]+(ll)fabs(h[i+j]-h[i]));
        }
    }
    cout<<dp[N-1]<<endl;
}