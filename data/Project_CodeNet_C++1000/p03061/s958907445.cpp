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
        vector<int> pre(n + 2), suf(n + 2);
        for (int i = 1; i <= n; i++) {
                pre[i] = __gcd(pre[i - 1], a[i - 1]);
        }
        for (int i = n; i >= 1; i--) {
                suf[i] = __gcd(suf[i + 1], a[i - 1]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
                ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
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
