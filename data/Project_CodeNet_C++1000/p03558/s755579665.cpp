#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
vector<pii>G[MAXN];
int n, dis[MAXN];
bool vis[MAXN];
int dijkstra(int s)
{
    for (int i = 0; i <= n; i++) dis[i] = 1e9, vis[i] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({dis[s] = 0, s});
    while (pq.size())
    {
        int u = pq.top().sec; pq.pop();
        if (vis[u]) continue; 
        vis[u] = 1;
        for (pii e : G[u])
        {
            int v = e.sec, w = e.fir;
            if (dis[v] > dis[u] + w)
                pq.push({dis[v] = dis[u] + w, v});
        }
    }
    return s + dis[0];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) 
    {
        if (i % 10 < 9) G[i].emplace_back(1, (i + 1) % n);
        G[i].emplace_back(0, (i * 10) % n);
    }
    int ans = 1e9;
    for (int s = 1; s < 10; s++) ans = min(ans, dijkstra(s)); 
    printf("%d\n", ans);
    return 0;
}