#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll x[1010], y[1010], z[1010];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = 0;
    for (int bits = 0; bits < (1<<3); bits++){
        vector<ll> vtmp;
        rep(i, n){
            ll tmp = 0;
            if (bits&(1<<0)) tmp += x[i];
            else tmp -= x[i];
            if (bits&(1<<1)) tmp += y[i];
            else tmp -= y[i];
            if (bits&(1<<2)) tmp += z[i];
            else tmp -= z[i];
            vtmp.push_back(tmp);
        }
        sort(vtmp.begin(), vtmp.end(),greater<ll>());
        ll cnt = 0;
        rep(i, m) cnt += vtmp[i];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}