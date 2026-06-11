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
        int n, k; cin >> n >> k;
        double ans = 0;
        for (int res = 1; res <= n; res++) {
                int temp = res;
                double xar = 1;
                while (temp >= 1 && temp <= k - 1) {
                        temp *= 2;
                        xar /= 2;
                }


                ans += xar / n;
        }

        cout << fixed << setprecision(10) << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
