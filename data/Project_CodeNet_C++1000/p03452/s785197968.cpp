#include <bits/stdc++.h>
#define MAXN 100001
#define inf 1<<30
using namespace std;
struct node {
    int x, dist;
    node(int _x, int _dist) {
        x = _x;
        dist = _dist;
    }
};
vector<node> G[MAXN];
int cost[MAXN];
bool viz[MAXN], flag = false;
int N, M;
void dfs(int node) {
    int next;
    if (flag == true) {
        return;
    }
    viz[node] = true;
    for (int i = 0; i < G[node].size(); ++i) {
        next = G[node][i].x;
        if (viz[next] == false) {
            cost[next] = cost[node] + G[node][i].dist;
            dfs(next);
        } else if (cost[next] != cost[node] + G[node][i].dist) {
            flag = true;
            return;
        }
    }
}
int main()
{
    int l, r, dist;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> l >> r >> dist;
        G[l].push_back(node(r, dist));
        G[r].push_back(node(l, -dist));
    }
    for (int i = 1; i <= N; ++i) {
        if (viz[i] == false) {
            cost[i] = 0;
            dfs(i);
        }
        if (flag == true) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
