// https://atcoder.jp/contests/abc100/tasks/abc100_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

struct Cake {
    int x, y, z;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<Cake> v(N);
    for (auto &t : v) {
        cin >> t.x >> t.y >> t.z;
    }
    int maxv = 0;
    // x, y, zで±を反転
    REP(i, 8) {
        sort(ALL(v), [&](Cake const &lhs, Cake const &rhs) {
            int ls = lhs.x * (i & 1 ? 1 : -1) + lhs.y * (i & 2 ? 1 : -1) +
                     lhs.z * (i & 4 ? 1 : -1);
            int rs = rhs.x * (i & 1 ? 1 : -1) + rhs.y * (i & 2 ? 1 : -1) +
                     rhs.z * (i & 4 ? 1 : -1);
            // 降順（大きい順）
            return ls > rs;
        });
        int sum = 0;
        REP(j, M) {
            sum += v[j].x * (i & 1 ? 1 : -1) + v[j].y * (i & 2 ? 1 : -1) +
                   v[j].z * (i & 4 ? 1 : -1);
        }
        maxv = max(maxv, sum);
    }
    cout << maxv << endl;

    return 0;
}
