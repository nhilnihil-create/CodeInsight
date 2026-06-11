#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m;
  cin >> n >> m;
  if (n >= m)
  {
    cout << 0;
    return;
  }

  vector<ll> x(m);
  for(int i = 0; i < m; ++i)
  {
    cin >> x[i];
  }

  sort(x.begin(), x.end());
  vector<ll> diff(m - 1);
  for(int i = 0; i < m - 1; ++i)
  {
    diff[i] = x[i + 1] - x[i];
  }
  sort(diff.begin(), diff.end());
  cout << accumulate(diff.begin(), next(diff.begin(), m - n), 0);

}

int main()
{
  fastio;
  solve();

  return 0;
}