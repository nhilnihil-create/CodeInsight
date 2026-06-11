#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

const int N = 301;
char s[N];
int k;
int d[N][N][N];
inline void Max(int &x, int y)
{
  if (x < y) x = y;
}
int dp(int l, int r, int k)
{
  if (l > r) return 0;
  int &ret = d[l][r][k];
  if (ret == -1)
    {
      if (l == r) return ret = 1;
      if (s[l] == s[r]) return ret = 2 + dp(l+1, r-1, k);
      ret = 0;
      Max(ret, dp(l, r-1, k));
      Max(ret, dp(l+1, r, k));
      if (k != 0)
        Max(ret, 2 + dp(l+1, r-1, k-1));
    }
  return ret;
}
int main()
{
  scanf("%s %d", s, &k);
  memset(d, -1, sizeof(d));
  printf("%d\n", dp(0, strlen(s)-1, k));
}
