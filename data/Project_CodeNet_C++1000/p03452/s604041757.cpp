#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<ll, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void dfs(int a, int x, vector<ll>& where, const vector<vector<pair<int,int>>>& adj) {
        if (where[a] != LLONG_MAX) {
                if (where[a] == x) return;
                else {
                        cout << "No\n";
                        exit(0);
                }
        }
        where[a] = x;
        for (auto b: adj[a]) {
                dfs(b.first, b.second + x, where, adj);
        }
}



void _main() {
        int n, m; cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
                int a, b, c; cin >> a >> b >> c;
                adj[a].emplace_back(b, c);
                adj[b].emplace_back(a, -c);
        }

        vector<ll> where(n + 1, LLONG_MAX);
        for (int i = 1; i <= n; i++) {
                if (where[i] != LLONG_MAX) continue;
                dfs(i, 0, where, adj);
        }

        cout << "Yes";
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}