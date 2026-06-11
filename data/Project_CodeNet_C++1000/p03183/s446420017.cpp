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
ll dp[1010][20010] = {};

typedef struct {
    ll w;
    ll s;
    ll v;
} P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll w[1010], s[1010], v[1010];
    rep(i,0,N) cin >> w[i] >> s[i] >> v[i];
    vector<P> vp;
    rep(i,0,N) vp.push_back({w[i], s[i], v[i]});
    sort(vp.begin(), vp.end(), [](P p1, P p2){
        return min(p1.s, p2.s - p1.w) > min(p2.s, p1.s - p2.w);
    });
    rep(i,0,N){
        w[i] = vp[i].w;
        s[i] = vp[i].s;
        v[i] = vp[i].v;
    }
    rep(i,0,N){
        rep(j,0,20001){
            if(j <= s[i]){
                dp[i+1][j + w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(i,0,20001) ans = max(ans, dp[N][i]);
    print(ans);

    

}