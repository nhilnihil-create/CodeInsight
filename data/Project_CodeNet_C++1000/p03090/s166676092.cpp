#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> res;
    if (N % 2 == 1) {
        int S = N * (N - 1) / 2;
        FOR(i, 1, N) {
            FOR(j, i + 1, N + 1) {
                if (i + j != N) {
                    res.emplace_back(i, j);
                }
            }
        }
    } else {
        int S = (N + 1) * (N / 2 - 1);
        FOR(i, 1, N) {
            FOR(j, i + 1, N + 1) {
                if (i + j != N + 1) {
                    res.emplace_back(i, j);
                }
            }
        }
    }
    cout << res.size() << endl;
    for (auto &p : res) {
        int i, j;
        tie(i, j) = p;
        cout << i << " " << j << endl;
    }

    return 0;
}
