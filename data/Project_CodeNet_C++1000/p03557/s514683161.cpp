#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

vec a, b, c;
lint res = 0;

int main() {
    int n;
    cin >> n;
    a.resize(n); b.resize(n); c.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(all(a));
    sort(all(b));
    sort(all(c));

    vec b_cnt(n);
    rep(i, n) b_cnt[i] = (c.end() - upper_bound(all(c), b[i]));

    vec b_cnts(n);
    b_cnts[n-1] = b_cnt[n-1];
    for (int i = n-2; i >= 0; --i) b_cnts[i] = b_cnts[i+1] + b_cnt[i];

    rep(i, n) {
        int j = upper_bound(all(b), a[i]) - b.begin();
        if (j == n) break;

        res += b_cnts[j];
    }

    cout << res << endl;
    return 0;
}