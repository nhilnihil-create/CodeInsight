#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a, b;
  int ans = 0;
  cin >> a >> b;
  for (ll i = a; i <= b; i++)
  {
    string buf = to_string(i);
    if (
        (buf[0] == buf[1] && buf[1] == buf[3] && buf[3] == buf[4]) ||
        (buf[0] == buf[4] && buf[1] == buf[3]))
    {
      ans++;
    }
  }
  cout << ans << endl;
}
