#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n, yin;
  cin >> n >> yin;
  yin /= 1000;
  for(int x = 0; x <= yin/10 + 1; ++x)
  {
    for(int y = 0; y <= yin/5 + 1; ++y)
    {
      int z = n - x - y;
      if (z < 0) continue;
      if (10 * x + 5 * y + z == yin)
      {
        cout << x << " " << y << " " << z;
        return;
      }
    }
  }
  cout << "-1 -1 -1";
}

int main()
{
  fastio;
  solve();

  return 0;
}