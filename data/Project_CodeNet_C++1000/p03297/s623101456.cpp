#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <regex>
#include <numeric>
#include <queue>
#include <set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

void swap(ll a, ll b)
{
  ll tmp = a;
  a = b;
  b = tmp;
}

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  if (a < b)
    swap(a, b);
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll vgcd = gcd(a, b);
  return (a / vgcd) * (b / vgcd) * vgcd;
}

int main(int argc, char const *argv[])
{
  ll t;
  cin >> t;
  REP(i, t)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > d || a < b)
    {
      cout << "No" << endl;
      continue;
    }
    ll cur = a;
    ll vgcd = gcd(max(b, d), min(b, d));

    if (a <= c)
    {
      if (b == d)
      {
        cout << "Yes" << endl;
        continue;
      }
      a = a + (d - b) * ((c - a) / (d - b));
    }
    if (a - ((a - (c + 1)) / vgcd) * vgcd - b >= 0)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}
