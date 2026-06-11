#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll K;
bool find_lower(ll a, vector<ll>& A)
{
  for (ll i = 0; i < K; ++i)
  {
    a -= a % A.at(i);
    if (a < 2)
    {
      return false;
    }
  }
  // cout << a << endl;
  return true;
}

bool find_uppper(ll a, vector<ll>& A)
{
  for (ll i = 0; i < K; ++i)
  {
    a -= a % A.at(i);
    if (a <= 2)
    {
      return false;
    }
  }
  // cout << a << endl;
  return true;
}

int main()
{
  cin >> K;
  vector<ll> A(K);
  pll ans;
  for (ll i = 0; i < K; ++i)
  {
    cin >> A.at(i);
  }
  ll lower_l = 1, lower_r = INF;
  ll m;
  while (lower_l != lower_r - 1)
  {
    m = (lower_r + lower_l) / 2;
    if (find_lower(m, A))
    {
      lower_r = m;
    }
    else
    {
      lower_l = m;
    }
  }
  ans.first = lower_r;
  ll upper_l = 1, upper_r = INF;
  while (upper_l != upper_r - 1)
  {
    m = (upper_r + upper_l) / 2;
    if (find_uppper(m, A))
    {
      upper_r = m;
    }
    else
    {
      upper_l = m;
    }
  }
  ans.second = upper_l;
  if (ans.first > ans.second)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.first << ' ' << ans.second << endl;
}
