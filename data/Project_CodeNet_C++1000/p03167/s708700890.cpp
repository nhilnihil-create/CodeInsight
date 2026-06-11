#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     F               first
#define     S               second
#define     t()             int test;cin>>test;while(test--)
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
#define     sz(x)           (int)(x).size()
#define     grid            vector<vector<ll> >
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
  //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int const p = 1000000007;

vector<string> path;

bool valid(int r, int c)
{
  if (r >= 0 && c >= 0 && path[r][c] == '.')
    return true;

  return false;
}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  IOS;

  int n, m;

  cin >> n >> m;

  path.resize(n);

  for (auto& i : path)cin >> i;

  grid dp(n + 1, std::vector<ll>(m + 1, 0));

  dp[0][0] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (valid(i - 1, j))
        dp[i][j] = ((dp[i][j] % p) + (dp[i - 1][j] % p)) % p;

      if (valid(i, j - 1))
        dp[i][j] = ((dp[i][j] % p) + (dp[i][j - 1] % p)) % p;
    }
  }

  cout << dp[n - 1][m - 1] << endl;





}