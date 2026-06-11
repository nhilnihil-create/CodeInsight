/*
一个点从u移到相邻节点v时，若删掉(u,v)后u这边的连通块大小为sizu，v这边的连通块大小为sizv，那么dv=du−sizv+sizu
所以考虑按d从大到小（也就是从叶子向上，这样能得到正确的siz）的顺序确定每个点x的父亲：这个点的d必须是dx−(n−sizx)+sizx
然后判一下根
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, v2[N], fa[N], sz[N];
long long v[N], ds[N];
map<long long, int> tp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &v[i]), tp[v[i]] = v2[i] = i, sz[i] = 1;
  sort(v2 + 1, v2 + n + 1, [&](int a, int b) {return v[a] < v[b];});
  for (int i = n; i > 1; i--) {
    long long tp2 = v[v2[i]] - n + sz[v2[i]] * 2;
    if (!tp[tp2]) return 0 & puts("-1");
    int sb = tp[tp2];
    ds[sb] += ds[v2[i]] + sz[v2[i]];
    sz[sb] += sz[v2[i]];
    fa[v2[i]] = sb;
  }
  if (ds[v2[1]] != v[v2[1]]) {printf("-1\n"); return 0;}
  for (int i = 1; i <= n; i++)if (fa[i])
      printf("%d %d\n", i, fa[i]);
  return 0;
}