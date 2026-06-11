#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  string n;
  cin >> n;
  bool ok = true;
  char before = n[0];
  for (ll i = 0; i < n.size(); ++i)
  {
    if (i == 0)
    {
      continue;
    }
    if (n[i] < before)
    {
      break;
    }
    if (n[i] == before)
    {
      continue;
    }
    ok = false;
    break;
  }
  if (ok)
  {
    for (ll i = 0; i < n.size(); ++i)
    {
      cout << n[0];
    }
  }
  else
  {
    for (ll i = 0; i < n.size(); ++i)
    {
      cout << n[0] - '0' + 1;
    }
  }
  cout << endl;
}
