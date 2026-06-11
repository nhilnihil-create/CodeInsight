#include <bits/stdc++.h>
#define INF 1000000001
#define ll long long
using namespace std;
using pint = pair<int, int>;

int main()
{
  ll X, Y;
  cin >> X >> Y;
  ll ans = 0;
  while (X <= Y)
  {
    X *= 2;
    ans += 1;
  }
  cout << ans << endl;
}
