/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll dp[3010][3010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll sum[3010] = {};
    rep(i,1,N+1){
        dp[0][N-i] = 1;
    }
    rep(i,0,N) sum[i+1] = sum[i] + dp[0][i];

    rep(i,1,N){
        rep(j,0,N-i){
            if(S[i-1] == '<'){
                dp[i][j] += (sum[N] - sum[j+1] + MOD) % MOD;
                dp[i][j] %= MOD;
            }else{
                dp[i][j] += (sum[j+1] - sum[0] + MOD) % MOD;
                dp[i][j] %= MOD;
            }
        }
        sum[0] = 0;
        rep(j,0,N){
            sum[j+1] = sum[j] + dp[i][j];
            sum[j+1] %= MOD;
        }
    }
    ll ans = 0;
    rep(i,0,N) (ans += dp[N-1][i]) %= MOD;
    print(ans);

    

}