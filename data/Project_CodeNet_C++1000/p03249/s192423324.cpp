#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 123456;
int num[MAXN];
LL D[MAXN], sz[MAXN];
vector<int> G[MAXN];
map<LL, int> mp;

bool cmp(int a, int b) {
     return D[a] > D[b];
}

LL dfs(int cur, LL dis) {
   LL sum = 0;
   for (int i : G[cur]) {
       sum += dfs(i, dis + 1);
   }
   return sum + dis;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        num[i] = i;
        sz[i] = 1;
        scanf("%lld", &D[i]);
        mp[D[i]] = i;
    }
    sort(num + 1, num + 1 + N, cmp);
    for (int i = 1; i < N; i++) {
        int cur = num[i];
        LL cur_D = D[cur];
        LL par_D = cur_D - N + 2 * sz[cur];
        if (mp.find(par_D) == mp.end()) return !printf("-1\n");
        int par = mp[par_D];
        G[par].push_back(cur);
        sz[par] += sz[cur];
    }
    LL check = dfs(num[N], 0);
    if (check != D[num[N]]) return !printf("-1\n");
    for (int i = 1; i <= N; i++) {
        for (int j : G[i]) {
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}
