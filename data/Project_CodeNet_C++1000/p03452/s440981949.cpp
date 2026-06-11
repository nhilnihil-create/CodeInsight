#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <deque>
 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 123456;
vector<pii> G[MAXN];
bool visit[MAXN];
int dis[MAXN];
 
bool dfs(int cur, int ds) {
     visit[cur] = 1;
     dis[cur] = ds;
     bool OK = true;
     for (auto i : G[cur]) {
         int to = i.first;
         int w = i.second;
         if (visit[to] && dis[to] != dis[cur] + w) {
            // printf("cur = %d to = %d dis[to] = %d outw = %d\n", cur, to, dis[to], dis[cur] + w);
            OK = false;
         }
         else if (!visit[to] && !dfs(to, dis[cur] + w)) OK = false;
     }
     return OK;
}
 
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        G[x].push_back(make_pair(y, d));
        G[y].push_back(make_pair(x, -d));
    }
    bool OK = true;
    for (int i = 1; i <= N; i++) {
        if (!visit[i] && !dfs(i, 0)) OK = false;
    }
    puts(OK ? "Yes" : "No");
    return 0;
}