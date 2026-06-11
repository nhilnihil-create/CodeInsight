#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


void dfs(int a, const vector<vector<int>>& adj, vector<bool>& vis, vector<int>& cc) {
        cc.emplace_back(a);
        vis[a] = 1;
        for (auto b: adj[a]) {
                if (!vis[b]) {
                        dfs(b, adj, vis, cc);
                }
        }
}


void _main() {
        int n, m; cin >> n >> m;
        vector<int> perm(n + 1);
        for (int i = 1; i <= n; i++) cin >> perm[i];
        vector<vector<int>> adj(n + 1);
        while (m--) {
                int a, b; cin >> a >> b;
                adj[a].emplace_back(b);
                adj[b].emplace_back(a);
        }

        vector<bool> vis(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;
                vector<int> cc;
                dfs(i, adj, vis, cc);
                vector<int> bb;
                for (auto it: cc) bb.emplace_back(perm[it]);
                sort(all(bb));
                sort(all(cc));
                for (auto b: bb) {
                        ans += binary_search(all(cc), b);
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
