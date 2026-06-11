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
        vector<tuple<string, int, int>> a(n);
        for (int i = 0; i < n; i++) {
                cin >> get<0>(a[i]) >> get<1>(a[i]);
                get<2>(a[i]) = i + 1;
                get<1>(a[i]) = -get<1>(a[i]);
        }

        sort(all(a));
        for (int i = 0; i < n; i++) cout << get<2>(a[i]) << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
