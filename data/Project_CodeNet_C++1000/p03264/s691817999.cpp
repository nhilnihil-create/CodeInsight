#include <bits/stdc++.h>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;
using ll = long long;

int main(void)
{
  int k;
  cin >> k;
  int res = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i % 2 == 0 && j % 2 == 1) ++res;
    }
  }
  cout << res << endl;
}