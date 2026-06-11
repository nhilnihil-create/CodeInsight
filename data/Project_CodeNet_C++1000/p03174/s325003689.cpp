#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++) //ここだけ閉区間にしています。
#define INF 10000000000
#define MOD 1000000007
using ll = long long;

#define bit(n,k) ((n>>k)&1)
int bit_count(ll S){
    int res = 0;
    while(S){
        if(S & 1)res++;
        S = S>>1;
    }
    return res;
}

int main(){
    int N; cin>>N;
    vector<vector<ll>> A(N,vector<ll> (N,0));
    rep(i,N)rep(j,N)cin>>A[i][j];
    vector<ll> dp(1<<N,0);
    dp[0] = 1;
    rep(S,1<<N){
        int i = bit_count(S);
        rep(j,N){
            if(bit(S,j)==1&&A[i-1][j]==1){
                dp[S] = (dp[S^(1<<j)] + dp[S])%MOD;
            }
        }
    }
    cout<<dp[(1<<N)-1]<<endl;
}