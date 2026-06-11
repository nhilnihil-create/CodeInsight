#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#define ll long long
#define rep(i, a, b) for(int i = a; i <= (int)b; i++)
void read(int &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
void read(ll &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
using namespace std;
const int maxn = 100010;
int n, Size[maxn], weight[maxn];
ll d[maxn], dis[maxn];
vector < pair <int, int > > ans;
vector <int> edge[maxn];
void dfs(int u, int fa) {
    Size[u] = 1;
    for(int i = 0; i < edge[u].size(); i++) if(edge[u][i] != fa) {
        int v = edge[u][i];
        dfs(v, u);
        dis[u] += dis[v] + Size[v];
        Size[u] += Size[v];
    }
}
int main()
{
    read(n);
    map <ll, int> mp;
    rep(i, 1, n) read(d[i]), mp[d[i]] = i, weight[i] = 1;
    rep(times, 1, n - 1) {
        map <ll, int> :: iterator it = --mp.end();
        int i = it -> second;
        ll want = d[i] + 2 * weight[i] - n;
        if(mp.find(want) == mp.end() || mp[want] == i) {
            puts("-1");
            return 0;
        }
        int j = mp[want];
        weight[j] += weight[i];
        ans.push_back(make_pair(i, j));
        edge[i].push_back(j), edge[j].push_back(i);
        mp.erase(--mp.end());
    }
    dfs(1, 0);
    if(dis[1] != d[1]) {
        puts("-1");
        return 0;
    }
    rep(i, 0, n - 2) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}