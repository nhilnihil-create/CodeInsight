#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int N = 18;
const int B = 1<<N;
const int D = 2;
struct Maxi
{
  int a[D];
  void update(int x)
  {
    for (int i = 0; i < D; ++i)
      if (a[i] < x) swap(x, a[i]);
  }
  void update(const Maxi &rhs)
  {
    for (int i = 0; i < D; ++i) update(rhs.a[i]);
  }
  void init(int x)
  {
    memset(a, 0, sizeof(a));
    a[0] = x;
  }
  ll sum()
  {
    ll ret = 0;
    for (int i = 0; i < D; ++i) ret += a[i];
    return ret;
  }
} d[B];
int main()
{
  int n;
  while (~scanf("%d", &n))
    {
      for (int i = 0; i < (1<<n); ++i)
	{
	  int x; scanf("%d", &x);
	  d[i].init(x);
	}
      for (int i = 0; i < n; ++i)
	for (int j = 0; j < (1<<n); ++j)
	  if ((j>>i)&1)
	    d[j].update(d[j^(1<<i)]);
      ll ans = 0;
      for (int i = 1; i < (1<<n); ++i)
	{
	  ans = max(ans, d[i].sum());
	  printf("%lld\n", ans);
	}
    }
}
