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
    int k;
    vector<ll> a;
    void input() {
        cin >> k;
        a.resize(k);
        REP(i, k) { cin >> a[i]; }
    }
    void output() {
        ll n_max = 2, n_min = 2;
        REPR(i, k) {
            if (n_min % a[i] && n_min % a[i] + (n_max - n_min) < a[i]) {
                cout << -1 << endl;
                return;
            }
            n_max = n_max / a[i] * a[i] + a[i] - 1;
            n_min = ((n_min - 1) / a[i] + 1) * a[i];
        }

        cout << n_min << " " << n_max << endl;
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
