#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll K;
  cin >> K;
  vector<ll> A(K);
  for (ll i = 0; i < K; ++i)
  {
    cin >> A.at(i);
  }
  if (A.at(K - 1) != 2)
  {
    cout << -1 << endl;
    return 0;
  }
  ll l = 2, r = 2;
  for (ll i = K - 1; i >= 0; --i)
  {
    l = (l / A.at(i) + (l % A.at(i) == 0 ? 0:1)) * A.at(i);
    r = r / A.at(i) * A.at(i) + A.at(i) - 1;
    if (r < l)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << ' ' << r << endl;
}
