#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}

int main()
{
  ll N, X;
  cin >> N;
  vector<ll> x(N + 1);
  for (ll i = 0; i < N + 1; i++)
  {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  vector<ll> y(N);
  ll ans = 1e9 + 7;

  if (x.size() < 3)
  {
    cout << x[1] - x[0] << endl;
    return 0;
  }

  for (ll i = 0; i < N - 1; i++)
  {
    ans = min(ans, gcd(abs(x[i] - x[i + 1]), abs(x[i + 1] - x[i + 2])));
  }
  cout << ans << endl;
}
