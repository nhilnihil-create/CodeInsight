#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn], dp[maxn];
int n, rt, sz[maxn], dep[maxn], tid[maxn];

map <ll, int> mp;
vector <int> e[maxn];

void DFS(int u) {
  for (int v : e[u]) {
    dep[v] = dep[u] + 1;
    dp[rt] += dep[v];
    DFS(v);
  }
}

void dfs(int u) {
  for (int v : e[u]) {
    dp[v] = dp[u] + n - 2 * sz[v], dfs(v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    tid[i] = i, sz[i] = 1;
    scanf("%lld", a + i), mp[a[i]] = i;
  }
  sort(tid + 1, tid + n + 1, [] (int x, int y) {
    return a[x] > a[y];
  });
  rt = tid[n];
  for (int i = 1; i < n; i++) {
    int u = tid[i];
    ll val = a[u] + 2 * sz[u] - n;
    map <ll, int> :: iterator it = mp.find(val);
    if (it == mp.end()) {
      return puts("-1"), 0;
    }
    int v = it -> second;
    sz[v] += sz[u], e[v].push_back(u);
  }
  DFS(rt), dfs(rt);
  for (int i = 1; i <= n; i++) {
    if (a[i] != dp[i]) {
      return puts("-1"), 0;
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int v : e[u]) {
      printf("%d %d\n", u, v);
    }
  }
  return 0;
}