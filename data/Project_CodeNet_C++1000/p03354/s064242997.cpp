//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;

const int MAXN = (int)1e5 + 5;
int p[MAXN];
bool vis[MAXN];
vector<int> adjList[MAXN];
set<int> st;

void dfs(int u) {
    vis[u] = 1;
    st.insert(u);
    for (int v : adjList[u])
        if (!vis[v])
            dfs(v);

}


int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            for (auto it : st) {
//                cout << it << endl;
                if (st.find(p[it]) != st.end())
                    ++ans;
            }
            st.clear();
        }
    }

    cout << ans << '\n';

    return 0;
}