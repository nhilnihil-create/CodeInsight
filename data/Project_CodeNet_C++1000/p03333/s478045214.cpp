#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
bool vis[maxn];
int n, a1[maxn], a2[maxn];

struct node {
  int l, r;
} a[maxn];

inline int get(int x, node &p) {
  if (p.r < x) return x - p.r;
  if (x < p.l) return p.l - x;
  return 0;
}

ll solve1() {
  memset(vis, 0, sizeof vis);
  ll ans = 0;
  int pos = 0, cnt = 0, p1 = 1, p2 = 1;
  while (cnt < n) {
    while (p1 <= n && vis[a1[p1]]) p1++;
    if (p1 <= n) {
      int x = a1[p1];
      if (a[x].r < pos) {
        goto GG;
      }
      vis[x] = 1, cnt++;
      ans += max(0, a[x].l - pos);
      pos = max(pos, a[x].l);
    }
    GG :
    while (p2 <= n && vis[a2[p2]]) p2++;
    if (p2 <= n) {
      int x = a2[p2];
      if (a[x].l > pos) {
        continue;
      }
      vis[x] = 1, cnt++;
      ans += max(0, pos - a[x].r);
      pos = min(pos, a[x].r);
    }
  }
  ans += abs(pos);
  return ans;
}

ll solve2() {
  memset(vis, 0, sizeof vis);
  ll ans = 0;
  int pos = 0, cnt = 0, p1 = 1, p2 = 1;
  while (cnt < n) {
    while (p2 <= n && vis[a2[p2]]) p2++;
    if (p2 <= n) {
      int x = a2[p2];
      if (a[x].l > pos) {
        goto GG;
      }
      vis[x] = 1, cnt++;
      ans += max(0, pos - a[x].r);
      pos = min(pos, a[x].r);
    }
    GG :
    while (p1 <= n && vis[a1[p1]]) p1++;
    if (p1 <= n) {
      int x = a1[p1];
      if (a[x].r < pos) {
        continue;
      }
      vis[x] = 1, cnt++;
      ans += max(0, a[x].l - pos);
      pos = max(pos, a[x].l);
    }
  }
  ans += abs(pos);
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a1[i] = a2[i] = i;
    scanf("%d %d", &a[i].l, &a[i].r);
  }
  sort(a1 + 1, a1 + n + 1, [] (int x, int y) {
    return a[x].l > a[y].l;
  });
  sort(a2 + 1, a2 + n + 1, [] (int x, int y) {
    return a[x].r < a[y].r;
  });
  printf("%lld", max(solve1(), solve2()));
  return 0;
}