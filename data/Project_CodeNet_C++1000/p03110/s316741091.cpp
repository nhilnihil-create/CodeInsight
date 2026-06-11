#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;

  cin >> N;

  double X;
  string U;
  double ans = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> X >> U;

    if (U == "JPY")
    {
      ans += X;
    }
    else
    {
      ans += X * 380000;
    }
  }

  cout << fixed << setprecision(8) << ans << endl;
}
