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
    vector<ll> A;
    void input() {
        cin >> N;
        A.resize(N);
        REP(i, N) { cin >> A[i]; }
    }
    void output() {
        if (A[0] > 0) {
            cout << -1 << endl;
            return;
        }
        ll res = 0;
        REP(i, N - 1) {
            if (A[i + 1] >= A[i] + 2) {
                cout << -1 << endl;
                return;
            }
            if (A[i + 1] > A[i]) {
                ++res;
            } else if (A[i + 1] > 0) {
                res += A[i + 1];
            }
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
