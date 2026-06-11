/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const int INF = 1e9;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll hash_val[200010] = {};
ll get_val(ll lv, ll rv){
    return hash_val[rv+1] ^ hash_val[lv];
}

int min_val[(1LL<<26)+10];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    rep(i,0,N){
        ll v = S[i] - 'a';
        hash_val[i+1] = (hash_val[i] ^ (1LL<<v));
    }
    int dp[200010] = {};
    dp[0] = 0;
    rep(i,0,N) dp[i+1] = INF;
    rep(i,0,(1LL<<26)+1) min_val[i] = INF;
    min_val[0] = 0;
    rep(i,0,N){
        ll tt = get_val(0,i);
        rep(j,0,26){
            ll v = (get_val(0, i) ^ (1LL<<j));
            dp[i+1] = min(dp[i+1], min_val[v]+1);
        }
        dp[i+1] = min(dp[i+1], min_val[tt] + 1);

        min_val[tt] = min(min_val[tt], dp[i+1]);
    }
    print(dp[N]);
}