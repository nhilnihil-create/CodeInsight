#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int h, w;

  cin >> h >> w;

  int a, b;
  cin >> a >> b;


  int ans = 0;
  ans = (h * w) - (a * w + b * h) + (a * b);

  cout << ans;
}
