#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  // これはアルゴリズム
  if (abs(A - B) >= 1e18)
  {
    cout << "Unfair" << endl;
  }
  else
  {
    if (K % 2 == 0)
    {
      cout << A - B << endl;
    }
    else
    {
      cout << B - A << endl;
    }
  }
  return 0;
}