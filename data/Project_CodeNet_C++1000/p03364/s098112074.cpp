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

class Main {
    int N;
    vector<string> S;
    void input() {
        cin >> N;
        S.resize(N);
        REP(i, N) {
            cin >> S[i];
        }
    }
    void output() {
        ll res = 0;
        REP(b, N) {
            bool ok = true;
            REP(i, N) {
                REP(j, N) {
                    if (S[i][(j + b) % N] != S[j][(i + b) % N]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) res += N;
        }
        cout << res << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
