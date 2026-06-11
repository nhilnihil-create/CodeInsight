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
    
    //l, r を二次元座標と捉える
    //cnt[i][j] : 座標i, jより左下の範囲の座標に位置する列車の数
    ll cnt[555][555] = {};
    rep(i, m){
        ll l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }

    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            cnt[i][j] += cnt[i][j-1]; 
        }
    }
    
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            cnt[i][j] += cnt[i-1][j]; 
        }
    }

    ll ans[q] = {};
    rep(i, q){
        ll a, b;
        cin >> a >> b;
        ans[i] =  cnt[b][b] + cnt[a-1][a-1] - cnt[a-1][b] - cnt[b][a-1];
    }

    rep(i, q)cout << ans[i] << endl;

}