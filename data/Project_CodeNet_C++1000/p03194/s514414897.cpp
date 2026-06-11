#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
int main()
{
  ll N, P;
  cin >> N >> P;
  if (N == 1)
  {
    cout << P << endl;
    return 0;
  }
  if (N > sqrt(P))
  {
    cout << 1 << endl;
    return 0;
  }
  ll ans = 1;
  for (int i = 2; i <= sqrt(P); i++)
  {
    int cnt = 0;
    while (P % i == 0)
    {
      P /= i;
      cnt++;
      if (cnt == N)
      {
        ans *= i;
        cnt = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
