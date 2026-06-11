#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, A, B, C;
ll mp(vector<ll>& which_stick, vector<ll>& L)
{
  ll res = -30;
  vector<ll> length(3, 0);
  for (ll i = 0; i < N; ++i)
  {
    if (which_stick.at(i) == 3)
    {
      continue;
    }
    res += 10;
    length.at(which_stick.at(i)) += L.at(i);
  }
  for (ll i = 0; i < 3; ++i)
  {
    if (length.at(i) == 0)
    {
      return INF;
    }
  }
  res += abs(A - length.at(0)) + abs(B - length.at(1)) + abs(C - length.at(2));
  return res;
}

void next(vector<ll>& which_stick)
{
  which_stick.at(N - 1) += 1;
  for (ll i = N - 1; i >= 0; --i)
  {
    if (which_stick.at(i) < 4)
    {
      return;
    }
    if (i == 0)
    {
      which_stick.at(0) = -1;
      return;
    }
    which_stick.at(i) %= 4;
    which_stick.at(i - 1) += 1;
  }
  return;
}

int main()
{
  cin >> N >> A >> B >> C;
  vector<ll> L(N);
  vector<ll> which_stick(N, 0);
  ll pattern = pow(4, N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> L.at(i);
  }
  ll ans = INF;
  for (ll i = 0; i < pattern; ++i)
  {
    ans = min(ans, mp(which_stick, L));
    next(which_stick);
  }
  cout << ans << endl;
}
