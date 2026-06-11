#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


void dfs(int a, int p, const vector<vector<pair<int, int>>>& adj, vector<int>& color) {
        for (const auto b: adj[a]) {
                if (b.first == p) continue;
                if (b.second % 2 == 0) color[b.first] = color[a];
                else color[b.first] = 1 - color[a];
                dfs(b.first, a, adj, color);
        }
}


void _main() {
        int n; cin >> n;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 1; i <= n - 1; i++) {
                int a, b, w; cin >> a >> b >> w;
                adj[a].emplace_back(b, w);
                adj[b].emplace_back(a, w);
        }

        vector<int> color(n + 1, -1);
        color[1] = 0;
        dfs(1, 0, adj, color);
        for (int i = 1; i <= n; i++) cout << color[i] << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
