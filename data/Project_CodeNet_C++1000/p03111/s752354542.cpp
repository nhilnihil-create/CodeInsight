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
    int a[3] = {};
    cin >> n;
    rep(i, 3) cin >> a[i];
    vec l(n);
    rep(i, n) cin >> l[i];

    int res = INF;

    vec pow_table;
    int cur = 1;
    rep(i, 10) {
        pow_table.push_back(cur);
        cur *= 4;
    }

    rep(flag, pow_table[n]) {
        int tres = 0;
        int kad[3] = {};
        int cnt[3] = {};

        rep(i, n) {
            int bits = (flag % pow_table[i+1]) / pow_table[i];
            if (bits == 0) continue;

            kad[bits-1] += l[i];
            cnt[bits-1]++;
        }

        bool emp = false;
        rep(i, 3) if (cnt[i] == 0) emp = true;
        if (emp) continue;

        rep(i, 3) tres += (cnt[i] - 1) * 10;

        rep(i, 3) tres += abs(kad[i] - a[i]);

        res = min(res, tres);
    }

    cout << res << endl;
    return 0;
}