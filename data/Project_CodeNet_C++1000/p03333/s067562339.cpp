#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long li;
template<class T>inline void read(T &x) {
  x = 0;
  T tmp = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') tmp = -1, c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + c - '0', c = getchar();
  x *= tmp;
}
template<class T>inline void Max(T &x, T y) {
  if (y > x) x = y;
}
template<class T>inline void Min(T &x, T y) {
  if (y < x) x = y;
}

const int N = 1e5 + 10;
int n;
pair<int, int> a[N];
bool b[N];

priority_queue<pair<int, int> >ql, qr;
li Solve(int cur) {
  li res = 0;
  while (!ql.empty()) ql.pop();
  while (!qr.empty()) qr.pop();
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; ++i) {
    ql.push(mp(a[i].first, i));
    qr.push(mp(-a[i].second, i));
  }
  int loc = 0;
  bool flag = 1;
  while (flag) {
    flag = 0;
    if (cur) {
      while (!ql.empty() && b[ql.top().second]) ql.pop();
      if (!ql.empty() && !b[ql.top().second]) {
	flag = 1;
	int now = ql.top().second;
	ql.pop();
	if (a[now].first <= loc) break;
	res += a[now].first - loc;
	b[now] = 1;
	loc = a[now].first;
      }
    } else {
      while (!qr.empty() && b[qr.top().second]) qr.pop();
      if (!qr.empty() && !b[qr.top().second]) {
	flag = 1;
	int now = qr.top().second;
	qr.pop();
	if (loc <= a[now].second) break;
	res += loc - a[now].second;
	b[now] = 1;
	loc = a[now].second;
      }
    }
    cur ^= 1;
  }
  return res + abs(loc);
}

int main(void) {
  read(n);
  for (int i = 0, x, y; i < n; ++i) {
    read(x), read(y);
    a[i] = mp(x, y);
  }
  li ans = max(Solve(0), Solve(1));
  printf("%lld\n", ans);

  return 0;
}
