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
        int a, b, c; cin >> a >> b >> c;
        int x, y; cin >> x >> y;
        c = min(2 * c, a + b);
        int ans = min(x, y) * c;
        x -= ans / c, y -= ans / c;
        int cnt = max(x, y) * c, ans1 = x * a + y * b;
        ans += min(cnt, ans1);
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
