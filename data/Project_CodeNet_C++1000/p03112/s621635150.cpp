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
    int A, B, Q;
    vector<ll> s, t, x;
    const ll INF = 1e11;
    void input() {
        cin >> A >> B >> Q;
        s.resize(A + 2);
        s[0] = -INF;
        s[A + 1] = INF;
        t.resize(B + 2);
        t[0] = -INF;
        t[B + 1] = INF;
        x.resize(Q);
        REP(i, A) { cin >> s[i + 1]; }
        REP(i, B) { cin >> t[i + 1]; }
        REP(i, Q) { cin >> x[i]; }
    }
    void output() {
        REP(q, Q) {
            ll res = INF;
            ll s_plus = *lower_bound(s.begin(), s.end(), x[q]);
            ll s_minus =
                *lower_bound(s.rbegin(), s.rend(), x[q], greater<ll>());
            ll t_plus = *lower_bound(t.begin(), t.end(), x[q]);
            ll t_minus =
                *lower_bound(t.rbegin(), t.rend(), x[q], greater<ll>());
            res = min(res, max(s_plus, t_plus) - x[q]);
            res = min(res, x[q] - min(s_minus, t_minus));
            res = min(res, 2 * s_plus - x[q] - t_minus);
            res = min(res, 2 * t_plus - x[q] - s_minus);
            res = min(res, x[q] - 2 * s_minus + t_plus);
            res = min(res, x[q] - 2 * t_minus + s_plus);
            cout << res << endl;
        }
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
