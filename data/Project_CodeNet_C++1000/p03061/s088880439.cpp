#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) (cerr << #x << " = " << x << endl;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0)
{
  if (fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

const int maxn = 2e5 + 100;
int a[maxn], pref[maxn];

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1 ; i <= n; i++)
  {
    cin >> a[i];
    pref[i] = __gcd(pref[i - 1], a[i]);
  }
  int g = 0;
  int ans = 0;
  for(int i = n ; i >= 1 ; i--)
  {
    auto c = __gcd(pref[i - 1], g);
    ans = max(ans, c);
    g = __gcd(g, a[i]);
  }
  cout << ans << endl;
  return 0;

}