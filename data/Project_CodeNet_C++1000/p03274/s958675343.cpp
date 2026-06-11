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
    int n, k;
    cin >> n >> k;
    vec x(n);
    rep(i, n) cin >> x[i];

    int res = INF;

    for (int i = 0; i + k - 1 < n; i++) {
        int l = x[i];
        int r = x[i+k-1];
        int d = r-l;
        res = min(res, d + abs(l));
        res = min(res, d + abs(r));
    }

    cout << res << endl;
    return 0;
}