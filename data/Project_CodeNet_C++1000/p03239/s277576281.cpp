#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, T;
  cin >> N >> T;
  int ans = 10000;
  bool flg = false;
  for (int i = 0; i < N; i++)
  {
    int c, t;
    cin >> c >> t;
    if (t <= T)
    {
      ans = min(ans, c);
      flg = true;
    }
  }
  if (flg)
  {
    cout << ans << endl;
  }
  else
  {
    cout << "TLE" << endl;
  }
}
