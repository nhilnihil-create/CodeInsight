#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


struct dsu {
        vector<int> par, rk;
        dsu(int n) {
                par.resize(n + 1);
                rk.resize(n + 1);
                for (int i = 1; i <= n; i++) {
                        par[i] = i;
                        rk[i] = 1;
                }
        }

        int find(int x) {
                while (x != par[x]) x = par[x];
                return x;
        }

        void unite(int a, int b) {
                a = find(a), b = find(b);
                if (a != b) {
                        if (rk[a] < rk[b]) swap(a, b);
                        par[b] = a;
                        rk[a] += rk[b];
                }
        }
};



void _main() {
        int n, m; cin >> n >> m;
        dsu d(n);
        while (m--) {
                int x, y, z; cin >> x >> y >> z;
                d.unite(d.find(x), d.find(y));
        }


        int cnt = 0;
        set<int> s;
        for (int i = 1; i <= n; i++) {
                s.emplace(d.find(i));
        }

        cout << sz(s);
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
