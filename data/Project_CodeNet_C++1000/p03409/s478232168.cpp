#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
class bipartite_matching {
public:
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> match;

    bipartite_matching(int n_) : n(n_), g(n_), match(n_), used(n_) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int maximum_matching(void) {
        int res = 0;
        fill(begin(match), end(match), -1);
        for (int v = 0; v < n; ++v) {
            if (match[v] == -1) {
                fill(begin(used), end(used), false);
                if (dfs(v)) res++;
            }
        }
        return res;
    }

private:
    std::vector<int> used;
    bool dfs(int v) {
        used[v] = true;
        for (int u : g[v]) {
            int w = match[u];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
};
bool judge(P r, P b) {
    return ((r.first < b.first) && (r.second < b.second));
}
int main() {
    int n; cin >> n;
    bipartite_matching bm(2*n);
    vector<P> red(n);
    rep(i, n) {
        cin >> red[i].first >> red[i].second;
    }
    vector<P> blu(n);
    rep(i, n) {
        cin >> blu[i].first >> blu[i].second;
    }
    rep(i, n) {
        rep(j, n) {
            if(judge(red[i], blu[j])) {
                bm.add_edge(i, n+j);
            }
        }
    }
    cout << bm.maximum_matching() << endl;
}
