#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define FILLA(a, x) memset((a), (x), sizeof (a))
#define COPYA(a, b) memcpy((b), (a), sizeof (a))

using namespace std;

typedef long long li;
typedef unsigned long long lu;
const li infl = ~0LLU >> 2;

template <class T>
inline void Min(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
inline void Max(T &x, T y) {
  if (y > x) x = y;
}

const int mod = 1e9 + 7;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (int)((li)x * y % mod); }
inline int Mul(int x, int y, int z) { return Mul(x, Mul(y, z)); }
int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}
int Inv(int x) {
  return Pow(x, mod - 2);
}

// ----------------------------------------

const int maxn = 2e5;

int n, len[maxn];
map<int, int> str;

bool AddOne(int len, int maxc) {
  int i = len - 1;
  while (i >= 0 && str[i] == maxc - 1) {
    str[i] = 0;
    --i;
  }
  if (i == -1) {
    return false;
  }
  ++str[i];
  return true;
}

bool Check(int maxc) {
  str.clear();
  int slen = 0;
  for (int i = 0; i < n; ++i) {
    if (len[i] > slen) {
      slen = len[i];
      continue;
    }
    if (len[i] < slen) {
      while (!str.empty() && prev(str.end())->first >= len[i]) {
        str.erase(prev(str.end()));
      }
      slen = len[i];
    }
    if (!AddOne(slen, maxc)) {
      return false;
    }
  }
  return true;
}

int main(void) {
  scanf("%d", &n);
  bool can = true;
  for (int i = 0; i < n; ++i) {
    scanf("%d", len + i);
    if (i > 0 && len[i - 1] >= len[i]) {
      can = false;
    }
  }
  if (can) {
    puts("1");
    return 0;
  }

  int low = 2, high = n + 1;
  while (high - low > 1) {
    int mid = low + high >> 1;
    if (Check(mid - 1)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  printf("%d\n", low);
  return 0;
}
