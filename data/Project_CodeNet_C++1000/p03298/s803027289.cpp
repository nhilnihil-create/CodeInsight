#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long li;

const int maxn = 18, mod1 = 1e9 + 7, mod2 = 1e9 + 9, base = 31;

int n;
char s[maxn * 2 + 1];
map< pair<li, li>, int > f;

int main(void) {
  scanf("%d%s", &n, s);
  for (int x = 0; x < 1 << n; ++x) {
    int g1 = 1, g2 = 1, h1 = 1, h2 = 1;
    for (int i = 0; i < n; ++i) {
      if (x >> i & 1) {
        g1 = ((li)g1 * base + s[i] - 'a') % mod1;
        g2 = ((li)g2 * base + s[i] - 'a') % mod2;
      } else {
        h1 = ((li)h1 * base + s[i] - 'a') % mod1;
        h2 = ((li)h2 * base + s[i] - 'a') % mod2;
      }
    }
    li key1 = (li)g1 * mod2 + g2, key2 = (li)h1 * mod2 + h2;
    ++f[make_pair(key1, key2)];
  }
  reverse(s, s + 2 * n);
  li ans = 0;
  for (int x = 0; x < 1 << n; ++x) {
    int g1 = 1, g2 = 1, h1 = 1, h2 = 1;
    for (int i = 0; i < n; ++i) {
      if (x >> i & 1) {
        g1 = ((li)g1 * base + s[i] - 'a') % mod1;
        g2 = ((li)g2 * base + s[i] - 'a') % mod2;
      } else {
        h1 = ((li)h1 * base + s[i] - 'a') % mod1;
        h2 = ((li)h2 * base + s[i] - 'a') % mod2;
      }
    }
    li key1 = (li)g1 * mod2 + g2, key2 = (li)h1 * mod2 + h2;
    ans += f[make_pair(key1, key2)];
  }
  printf("%lld\n", ans);
  return 0;
}
