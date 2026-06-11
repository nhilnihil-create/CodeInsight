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
        int n, m, x; cin >> n >> m >> x;
        set<int> s;
        while (m--) {
                int w; cin >> w;
                s.emplace(w);
        }

        int ans = 1e9, cnt = 0;
        for (int i = x + 1; i <= n; i++) {
                if (s.count(i)) cnt++;
        }

        ans = cnt;
        cnt = 0;
        for (int i = x - 1; i >= 0; i--) {
                if (s.count(i)) cnt++;
        }

        cout << min(ans, cnt);
}




signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
