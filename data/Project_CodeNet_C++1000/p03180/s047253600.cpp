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
ll dp[1LL<<17] = {};
ll N;
ll a[18][18];
ll calc(ll state){
    ll &res = dp[state];
    if(~res) return res;
    res = 0;
    ll cnt = __builtin_popcount(state);
    if(cnt <= 1) return 0;
    rep(i,0,N){
        rep(j,i+1,N){
            if(((state>>i)&1) && ((state>>j)&1)) res += a[i][j];
        }
    }
    ll res2 = 0;
    for(int bit = (state-1) & state; ; bit = (bit-1) & state){
        if(bit == 0) break;
        res2 = max(res2, calc(bit) + calc(state - bit));
    }
    // rep(bit,0,state){
    //     res2 = max(res2, calc(bit) + calc(state|(~bit)));
    // }

    res = max(res, res2);
    return res;
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = calc((1LL<<N)-1);
    print(ans);

    

}