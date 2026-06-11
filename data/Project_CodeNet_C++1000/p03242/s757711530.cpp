#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  string n;
  cin >> n;
  for (ll i = 0; i < n.size(); ++i)
  {
    if (n[i] == '1')
    {
      cout << '9';
    }
    else if (n[i] == '9')
    {
      cout << '1';
    }
    else
    {
      cout << n[i];
    }
  }
  cout << endl;
}
