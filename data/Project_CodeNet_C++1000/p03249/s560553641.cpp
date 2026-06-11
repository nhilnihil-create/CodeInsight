#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOG(...) fprintf (stderr, __VA_ARGS__)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f, N = 100005;
const LL INFL = 0x3f3f3f3f3f3f3f3fll;

int n, sz[N], dep[N];
pair <LL, int> d[N];
bool cmp(pair <LL, int> a, pair <LL, int> b) { return a.first > b.first; }
map <int, int> mp;
vector <int> g[N];
void link(int x, int y){
    g[x].push_back(y);
//    g[y].push_back(x); 
}

void dfs(int u, int pre) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == pre) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() { 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &d[i].first), d[i].second = i, mp[d[i].first] = i; 

    sort (d + 1, d + n + 1, cmp);
    int root = d[n].second;
    for (int i = 1; i <= n; i++) sz[i] = 1; 
    for (int i = 1; i < n; i++) {
        LL fa = d[i].first - n + 2 * sz[d[i].second];
        if (mp[fa]) {
            int ff = mp[fa];
            if (ff == d[i].second) return 0*puts("-1");
            sz[ff] += sz[d[i].second]; link(ff, d[i].second); 
        }
        else return 0*puts("-1");
    }

    dfs (root, 0); 

    if (accumulate(dep + 1, dep + n + 1, 0LL) != d[n].first)
        return puts("-1"), 0; 
    for(int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++)
            cout << i << " " << g[i][j] << endl; 
    return 0;
}