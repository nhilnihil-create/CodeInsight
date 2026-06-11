#include <bits/stdc++.h>

using namespace std;

const int limit = 100010;
using edge = struct {int to; int w;};
vector<edge> tree[limit];
vector<int> color(limit, -1);

void dfs(int v, int p, int w){
    color[v] = w%2;
    for (auto &e : tree[v])
    {
        if (e.to == p)
        {
            continue;
        }
        dfs(e.to, v, w + e.w);
    }
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N-1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c %= 2;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    dfs(0, -1, 0);

    for (int i = 0; i < N; i++)
    {
        cout << color[i] << endl;
    }
    
}

int main() {
    solve();
    return 0;
}