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

int n;
vec c, s, f;

void solve(int start) {
    if (start == n-1) {
        cout << 0 << endl;
        return;
    }

    int res = 0;

    rep(i, n-1) {
        if (i < start) continue;

        if (res < s[i]) res = s[i];
        else {
            if (res % f[i] != 0) {
                res += f[i] - (res % f[i]);
            }
        }
        res += c[i];
    }

    cout << res << endl;
}

int main() {
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }

    c.resize(n-1);
    s.resize(n-1);
    f.resize(n-1);
    rep(i, n-1) cin >> c[i] >> s[i] >> f[i];

    rep(i, n) solve(i);
    return 0;
}