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
        int n, m; cin >> n >> m;
        vector<int> connected[m];
        for (int i = 0; i < m; i++) {
                int x; cin >> x;
                while (x--) {
                        int y; cin >> y;
                        connected[i].emplace_back(y - 1);
                }
        }

        vector<int> parity(m); cin >> parity;

        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
                bool good = 1;
                for (int i = 0; i < m; i++) {
                        int on = 0;
                        for (auto s: connected[i]) {
                                if (1 << s & mask) on++;
                        }
                        if (on % 2 != parity[i]) good = 0;
                }
                ans += good;
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
