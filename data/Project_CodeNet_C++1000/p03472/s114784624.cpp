#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, h;
    cin >> n >> h;
    vec a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int mx = 0;
    rep(i, n) {
        mx = max(mx, a[i]);
    }

    int res = 0;

    sort(all(b), greater<int>());

    rep(i, n) {
        if (b[i] > mx) {
            h -= b[i];
            res++;
        }
        if (h <= 0) break;
    }

    if (h > 0) {
        res += (h + mx - 1) / mx;
    }

    cout << res << endl;
    return 0;
}