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
        vector<int> a(n); cin >> a;

        vector<int> bits(20);
        ll ans = 0;
        for (int l = -1, r = 0; r < n; r++) {
                while (1) {
                        auto temp = bits;
                        bool ok = 1;
                        for (int bit = 0; bit < 20; bit++) {
                                temp[bit] += !!(1 << bit & a[r]);
                                ok &= temp[bit] <= 1;
                        }

                        if (ok) {
                                bits = temp;
                                break;
                        }

                        l++;
                        for (int bit = 0; bit < 20; bit++) {
                                bits[bit] -= !!(1 << bit & a[l]);
                        }
                }

                ans += r - l;
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
