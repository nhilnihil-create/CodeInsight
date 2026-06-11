#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  if (n < 10) 
  {
    cout << 0;
    return;
  }

  map<int, int> primes;
  for(int i = 1; i <= n; ++i)
  {
    int n = i;
    for(int p = 2; p <= i; ++p)
    {
      while(n % p == 0)
      {
        primes[p]++;
        n /= p;
      }
    }
  }

  int ans = 0;
  int over75 = 0;
  int over25 = 0;
  int over15 = 0;
  int over5 = 0;
  int over3 = 0;
  for(const auto& p : primes)
  {
    if (p.second >= 74) over75++;
    if (p.second >= 24) over25++;
    if (p.second >= 14) over15++;
    if (p.second >=  4) over5++;
    if (p.second >=  2) over3++;
  }

  ans += over75;
  ans += over25 * (over3 - 1);
  ans += over15 * (over5 - 1);
  ans += over5 * (over5 - 1) * (over3 - 2) / 2;

  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}