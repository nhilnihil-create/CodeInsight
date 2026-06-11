#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void chmax(T & a, T const & b) { a = max(a, b); }

int main() {
    // input
    int n; cin >> n;
    vector<int> l(n), r(n);
    REP (i, n) cin >> l[i] >> r[i];

    // solve
    sort(l.rbegin(), l.rend());
    sort(ALL(r));
    ll acc = 0;
    ll t = 0;
    REP (i, n) {
        chmax(acc, t + l[i]);
        chmax(acc, t - r[i]);
        chmax(acc, t + l[i] - r[i]);
        t += l[i] - r[i];
    }

    // output
    cout << 2 * acc << endl;
    return 0;
}
