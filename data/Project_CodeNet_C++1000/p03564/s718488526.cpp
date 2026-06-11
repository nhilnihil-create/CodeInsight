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

    int res = INF;

    rep(i, 1 << n) {
        int now = 1;

        rep(j, n) {
            int bt = (i >> j) & 1;
            if (bt) now += k;
            else now *= 2;
        }

        res = min(res, now);
    }

    cout << res << endl;
    return 0;
}