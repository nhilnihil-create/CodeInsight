#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
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

    unordered_map<int, int> pf;

    for (int i = 2; i <= n; i++) {
        int t = i;
        int j = 2;
        while (j * j <= t) {
            if (t % j == 0) {
                pf[j]++;
                t /= j;
            }
            else {
                j++;
            }
        }
        if (t > 1) pf[t]++;
    }

    int res = 0;

    int c2 = 0, c5 = 0, c14 = 0, c24 = 0, c74 = 0;

    for (auto&& p : pf) {
        if (p.second >= 74) c74++;
        if (p.second >= 24) c24++;
        if (p.second >= 14) c14++;
        if (p.second >= 4) c5++;
        if (p.second >= 2) c2++;
    }

    res += c74;

    res += c24 * (c2 - 1);

    res += c14 * (c5 - 1);

    res += c5 * (c5 - 1) * (c2 - 2) / 2;

    cout << res << endl;
    return 0;
}