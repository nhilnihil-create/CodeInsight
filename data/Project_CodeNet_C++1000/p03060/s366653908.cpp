#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n; cin >> n;
        vector<int> v(n); cin >> v;
        vector<int> c(n); cin >> c;
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
                int x = 0, y = 0;
                for (int bit = 0; bit < n; bit++) {
                        if (1 << bit & mask) {
                                x += v[bit];
                                y += c[bit];
                        }
                }
                ans = max(ans, x - y);
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
