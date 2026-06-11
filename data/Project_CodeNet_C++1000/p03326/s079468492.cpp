#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll a[12345678], b[12345678], c[12345678];
signed main() {
    ll n, k, ans = 0; cin >> n >> k;
    for (int h = 0; h < n; h++) {
        cin >> a[h] >> b[h] >> c[h];
    }
    for (int i = 0; i <= (1 << 3); i++) {
        vector<ll> sep = { }; ll sum = 0;
        for (int j = 0; j < 3; j++) {
            if ((i & (1 << j)) > 0) {
                sep.push_back(j);
            }
        }
        sep.push_back(INF); vector<ll> v;
        for (int h = 0; h < n; h++) {
            ll aa = a[h], bb = b[h], cc = c[h], z = 0;
            if (sep[z] == 0) { aa = 0 - aa; z++; }
            if (sep[z] == 1) { bb = 0 - bb; z++; }
            if (sep[z] == 2) { cc = 0 - cc; }
            v.push_back(aa + bb + cc);
            //cout << aa << ' ' << bb << ' ' << cc << endl;
        }
        sort(v.begin(), v.end()); reverse(v.begin(), v.end());
        for (int h = 0; h < k; h++) {
            sum += v[h];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}