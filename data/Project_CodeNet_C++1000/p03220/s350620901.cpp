#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, ans;
  double T, A;
  cin >> N >> T >> A;
  double temp = 1e9 + 7;

  for (int i = 0; i < N; i++)
  {
    double H;
    cin >> H;
    double buf = abs(A - (T - (H * 0.006)));
    if (temp >= buf)
    {
      ans = i + 1;
      temp = buf;
    }
  }
  cout << ans << endl;
}
