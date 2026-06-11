#include <bits/stdc++.h>
using namespace std;

static const int Maxn = 100005;

int n, id[Maxn];
int par[Maxn], sz[Maxn];
long long a[Maxn];
map<long long, int> mp;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    id[i] = i, sz[i] = 1;
    mp[a[i]] = i;
  }
  sort(id + 1, id + n + 1, [&](const int &x, const int &y)->bool {
    return a[x] > a[y];
  });
  for (int i = 1; i < n; ++i) {
    int now = id[i];
    par[now] = mp[a[now] - n + 2 * sz[now]];
    if (!par[now]) return puts("-1") & 0;
    sz[par[now]] += sz[now];
  }
  long long sum = 0;
  for (int i = 1; i < n; ++i) sum += sz[id[i]];
  if (sum != a[id[n]]) return puts("-1") & 0;
  for (int i = 1; i < n; ++i)
    printf("%d %d\n", id[i], par[id[i]]);
  return 0;
}