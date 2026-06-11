// https://atcoder.jp/contests/abc128/tasks/abc128_c
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<set<int>> V(M);
    REP(i, M) {
        int k;
        cin >> k;
        REP(j, k) {
            int t;
            cin >> t;
            V[i].insert(t - 1);
        }
    }
    vector<bool> P(M);
    REP(i, M) {
        int t;
        cin >> t;
        P[i] = (t == 1);
    }
    int ans = 0;
    // ビット全探索
    REP(i, 1UL << N) {
        vector<int> cnt(M);
        REP(j, N) {
            if (i & (1UL << j)) {
                REP(k, M) {
                    if (V[k].count(j) > 0) {
                        cnt[k]++;
                    }
                }
            }
        }
        bool flag = true;
        REP(k, M) {
            if (cnt[k] % 2 != P[k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
