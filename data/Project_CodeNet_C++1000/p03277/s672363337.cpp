#include <algorithm>
#include <cstdio>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define For(i, l, r) for (int i = (l); i <= (r); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int maxn = 100000 + 5;

int n;
LL tot;
int a[maxn], b[maxn];
int s[maxn], tmp[maxn];

LL merge_sort(int l, int r) {
  if (l == r) return 0;
  LL ret = 0;
  int mid = (l + r) / 2;
  ret += merge_sort(l, mid);
  ret += merge_sort(mid + 1, r);
  int i = l, j = mid + 1;
  For(k, l, r) {
    if (i <= mid && (j > r || s[i] <= s[j]))
      tmp[k] = s[i++];
    else
      tmp[k] = s[j++], ret += i - l;
  }
  For(k, l, r) s[k] = tmp[k];
  return ret;
}

bool check(int x) {
  s[0] = 0;
  rep(i, n) s[i + 1] = s[i] + (a[i] > x ? 1 : -1);
  return merge_sort(0, n) <= tot - (tot / 2 + 1);
}

int main() {
  scanf("%d", &n);
  tot = (LL)n * (n + 1) / 2;
  rep(i, n) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  int l = 0, r = unique(b, b + n) - b - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(b[mid]))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", b[r]);

  return 0;
}