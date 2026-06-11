#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
 
const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    ll n, m, q;
    cin >> n >> m >> q;

    ll cnt[555][555] = {};
    rep(i, m){
        ll l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }

    ll sum[n+1][n+1] = {};
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            sum[i][j] = sum[i][j-1] + cnt[i][j]; 
        }
    }

    ll ans[q] = {};
    rep(i, q){
        ll a, b;
        cin >> a >> b;
        for(ll j = a; j <= b; ++j)ans[i] += sum[j][b] - sum[j][a-1];
    }

    rep(i, q)cout << ans[i] << endl;

}