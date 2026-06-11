#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll x[55], y[55];
int n, k;

vector<vector<int>> ret;

void prep(vector<int> v){
    if (v.size()==5) {
        ret.push_back(v);
        return;
    }
    int b = v.back();
    rep(i, n) {
        if (i < b) continue;
        v.push_back(i);
        prep(v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> k;
    rep(i, n) cin >> x[i] >> y[i];
    vector<int> ini;
    ini.push_back(0);

    prep(ini);
    ll ans = 5e18;

    rep(i, ret.size()){
        ll max_x = -LINF, max_y = -LINF, min_x = LINF, min_y = LINF;
        for(int j = 1; j <= min(k, 4); j++) {
            max_x = max(max_x, x[ret[i][j]]);
            min_x = min(min_x, x[ret[i][j]]);
            max_y = max(max_y, y[ret[i][j]]);
            min_y = min(min_y, y[ret[i][j]]);
        }
        int cnt = 0;
        rep(j, n) if (min_x <= x[j] && x[j] <= max_x && min_y <= y[j] && y[j] <= max_y) cnt++;
        if (cnt < k) continue;
        ans = min(ans, (max_x - min_x) * (max_y - min_y));
    }
    cout << ans << endl;

    return 0;
}
