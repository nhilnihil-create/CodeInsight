#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N){
        cin>>A.at(i);
    }
    vector<vector<ll>> dp(2,vector<ll>(N));
    dp[0][0]=A.at(0);
    dp[1][0]=-A.at(0);
    rep(i,N-2){
        chmax(dp[0][i+1],dp[0][i]+A.at(i+1));
        chmax(dp[0][i+1],dp[1][i]-A.at(i+1));
        chmax(dp[1][i+1],dp[0][i]-A.at(i+1));
        chmax(dp[1][i+1],dp[1][i]+A.at(i+1));
    }
    cout<<max(dp[0][N-2]+A.at(N-1),dp[1][N-2]-A.at(N-1))<<endl;
}