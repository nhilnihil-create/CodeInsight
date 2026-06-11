#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>

typedef long long LL;

LL read() {
  LL ans = 0; int c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 100050;
std::map<LL, int> M;

int n, siz[N], fa[N];
LL p[N];

int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    siz[M[read()] = i] = 1;
  for (std::map<LL, int>::iterator it = --M.end(); it != M.begin(); --it) {
    LL D = it->first;
    int i = it->second;
    LL t = D - n + 2 * siz[i];
    if (t >= D || !M.count(t)) { puts("-1"); return 0; }
    int j = M[t];
    siz[fa[i] = j] += siz[i];
    p[j] += siz[i] + p[i];
  }
  if (p[M.begin()->second] != M.begin()->first) {
    puts("-1"); return 0;
  }
  for (int i = 1; i <= n; ++i) if (fa[i])
    printf("%d %d\n", fa[i], i);
}
