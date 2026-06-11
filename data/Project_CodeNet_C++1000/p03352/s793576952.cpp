#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}

#define int long long


int exp(int a, int n) {
        int res = 1;
        while (n--) res *= a;
        return a;
}


void _main() {
        int x; cin >> x;
        int ans = 1;

        for (int a = 2, n; a <= x; a++) {
                int b = a * a;
                while (b <= x) {
                        if (abs(ans - x) > abs(b - x)) ans = b;
                        b *= a;
                }
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
