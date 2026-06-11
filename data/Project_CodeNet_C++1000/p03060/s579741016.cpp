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
    int n;
    cin >> n;
    vec v(n), c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];

    int res = -INF;

    rep(f, 1 << n) {
        int tres = 0;

        rep(i, n) {
            if ((f >> i) & 1) {
                tres += v[i];
                tres -= c[i];
            }
        }

        res = max(res, tres);
    }

    cout << res << endl;

    return 0;
}