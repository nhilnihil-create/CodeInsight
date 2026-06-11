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
int a[maxn];

ll dp[maxn][2];
bool vis[maxn][2];

int n;
ll solve(int pos, int change)
{
  int mult = 1;
  if(change)
    mult = -1;

  if(pos == n - 1)
  {
    return a[pos] * mult;
  }

  ll &ans = dp[pos][change];
  if(vis[pos][change])
    return ans;
  vis[pos][change] = 1;
  ans = numeric_limits<int>::min();
  ll val = a[pos] * mult;
  ll nVal = -val;
  ans = max(ans, solve(pos + 1, 1) + nVal);
  ans = max(ans, solve(pos + 1, 0) + val);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n ; i++)
    cin >> a[i];
  cout << solve(0, 0) << endl;
  return 0;

}