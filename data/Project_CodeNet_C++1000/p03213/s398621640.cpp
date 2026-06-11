#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//=============is_prime============================
bool is_prime(ll N)
{
  if (N == 1)
  {
    return false;
  }
  for (ll i = 2; i * i <= N; ++i)
  {
    if (N % i == 0)
    {
      return false;
    }
  }
  return true;
}
//=================================================

ll N;

ll count(ll a, ll b, vector<ll>& cnt)
{
  ll over_a = 0, over_b = 0;
  for (ll i = 0; i < 101; ++i)
  {
    if (cnt.at(i) >= a - 1)
    {
      over_a += 1;
    }
    if (cnt.at(i) >= b - 1)
    {
      over_b += 1;
    }
  }
  // cout << over_a << ' ' << over_b << endl;
  return (over_a - 1) * over_b;
}


int main()
{
  cin >> N;
  ll over2 = 0, over5 = 0;
  vector<ll> cnt(101, -1);
  for (ll i = 2; i < 101; ++i)
  {
    if (is_prime(i))
    {
      cnt.at(i) = 0;
    }
  }
  for (ll i = 2; i < N + 1; ++i)
  {
    ll temp = i;
    while (temp != 1)
    {
      for (ll j = 2; j <= temp; ++j)
      {
        if (temp % j == 0)
        {
          temp /= j;
          cnt.at(j) += 1;
          break;
        }
      }
    }
  }
  ll two = 0, five = 0;
  for (ll i = 0; i < 101; ++i)
  {
    if (cnt.at(i) >= 2)
    {
      two += 1;
    }
    if (cnt.at(i) >= 4)
    {
      five += 1;
    }
  }
  ll ans = (two - 2) * (five - 1) * five / 2;
  ans += count(3, 25, cnt) + count(5, 15, cnt);
  for (ll i = 0; i < 101; ++i)
  {
    if (cnt.at(i) >= 74)
    {
      ans += 1;
    }
  }
  cout << ans << endl;
  // cout << "ans" << ans << endl;
  // cout << "1:" << count(1, 75, cnt) << endl;
  // cout << "3:" << count(3, 25, cnt) << endl;
  // cout << "5:" << count(5, 15, cnt) << endl;
  // for (ll i = 0; i < 101; ++i)
  // {
  //   if (cnt.at(i) == 0)
  //   {
  //     continue;
  //   }
  //   cout << i << ' ' << cnt.at(i) << endl;
  // }
  // ll test = 1;
  // for (ll i = 1; i < 101; ++i)
  // {
  //   test *= pow(i, cnt.at(i));
  // }
  // cout << test << endl;
}
