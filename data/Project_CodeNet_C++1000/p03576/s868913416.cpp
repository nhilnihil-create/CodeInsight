#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    int n, K;
    cin >> n >> K;

    ll x[n], y[n];
    rep(i, n)cin >> x[i] >> y[i];

    ll ans = LINF;

    rep(i, n)for(int j = i+1; j < n; ++j){
        rep(k, n)for(int l = k+1; l < n; ++l){
            ll x_max = max(x[i], x[j]);
            ll x_min = min(x[i], x[j]);
            ll y_max = max(y[k], y[l]);
            ll y_min = min(y[k], y[l]);

            ll cnt = 0;
            rep(p, n){
                if(x[p] <= x_max && x[p] >= x_min && y[p] <= y_max && y[p] >= y_min){
                    cnt++;
                }
            }

            if(cnt >= K){
                ans = min(ans, (x_max-x_min)*(y_max-y_min));
            }
        }
    }

    cout << ans << endl;
}