#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int ans = 700;
  int flag = 0;

  rep(i, 3)
  {
    if (s.at(i) == 'o')
      flag++;
  }
  cout << ans + flag * 100;
}
