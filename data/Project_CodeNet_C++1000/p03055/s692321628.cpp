#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
vector<int> edge[maxn];
int dep[maxn];
int n, mx, mxpos;

void dfs(int u, int pre) {
    for (auto v :edge[u]) {
        if (v == pre) continue;
        dep[v] = dep[u] + 1;
        if (dep[v] > mx) {
            mx = dep[v];
            mxpos = v;
        }
        dfs(v, u);
    }
}

void dfs2(int u, int pre) {
    for (auto v :edge[u]) {
        if (v == pre) continue;
        dep[v] = dep[u] + 1;
        if (dep[v] > mx) {
            mx = dep[v];
        }
        dfs2(v, u);
    }
}

int main() {
    cin >>n;
    if (n == 1) {
        cout << "First" << endl;
        return 0;
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u>> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    dep[mxpos] = 1;
    dfs2(mxpos, 0);
    //sort(dep + 1, dep +1 +n);
    int res = (mx) % 3;
    if (res == 2) cout << "Second" << endl;
    else cout <<"First"<<endl;
    return 0;
}
