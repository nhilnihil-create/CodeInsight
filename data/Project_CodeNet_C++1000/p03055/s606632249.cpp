#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

vector<int> graph[200005];
int depth[200005];
int parent[200005];
int leafdis[200005];

int diameter = 0;

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    leafdis[node] = 1;
    vector<int> leafdis_val;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);
        leafdis_val.push_back(leafdis[nxt]);
        leafdis[node] = max(leafdis[node], leafdis[nxt] + 1);
    }
    if (leafdis_val.size() < 2) {
        diameter = max(diameter, leafdis[node]);
    } else {
        sort(leafdis_val.begin(), leafdis_val.end());
        reverse(leafdis_val.begin(), leafdis_val.end());
        diameter = max(diameter, leafdis_val[0] + leafdis_val[1] + 1);
    }
}


void inputtree(int siz, int root = 1)
{
    for (int i = 1; i < siz; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(root, 0);
}

int n;

int main()
{
    scanf("%d", &n);
    inputtree(n);
    //printf("%d\n", diameter);
    if (diameter % 3 == 2) {
        printf("Second");
    } else {
        printf("First");
    }
    return 0;
}
