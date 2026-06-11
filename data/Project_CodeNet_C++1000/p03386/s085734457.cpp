#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll a, b;
  cin >> a >> b;
  ll k;
  cin >> k;
  for (int i = a; i <= min(b, a + k - 1); i++)
  {
    cout << i << endl;
  }
  for (int i = max(b - k + 1, a + k); i <= b; i++)
  {
    cout << i << endl;
  }

  return 0;
}