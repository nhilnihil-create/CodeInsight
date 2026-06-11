#include <bits/stdc++.h>
#define rint register int 
using namespace std;
const int Maxn = 1e5 + 5;

char buf[1 << 20], *p1, *p2;
#define getchar() ((p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
int read() {
	rint s = 0, f = 1; register char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * f;
}

int n, tot = 0, a[Maxn], b[Maxn], sum[Maxn];

int l, r;

struct Treearray {
  
  int c[Maxn << 1];
  void clear() { for (rint i = 1; i <= n * 2; ++i) c[i] = 0; }
  void add(int x, int y) { for (; x <= n * 2; x += (x & -x)) c[x] += y; }
  int query(int x) {
    rint res = 0;
    for (; x; x -= (x & -x)) res += c[x];
    return res;
  }
} t;

void input() {
  n = read();
  for (rint i = 1; i <= n; ++i) a[i] = read(), r = max(r, a[i]);
  ++r;
}

namespace Solution {

  namespace Binary_ans {
    bool check(int mid) {
      t.clear();
      sum[0] = 0;
      for (rint i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (a[i] >= mid ? 1 : -1);
      long long res = 0;
      for (rint i = 0; i <= n; ++i) {
        res += t.query(sum[i] + n);
        t.add(sum[i] + n, 1);
      }
      return res >= 1LL * n * (n + 1) / 4;
    }
    void Binary() {
      while (r - l > 1) {
      	rint mid = (l + r) >> 1;
      	check(mid) ? l = mid : r = mid;
			}
    }
  } 

  void solve() {
    Binary_ans :: Binary();
    printf("%d\n", l);
  }
}

signed main() {
  input(); 
  Solution :: solve();
  return 0;
}