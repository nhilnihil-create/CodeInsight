#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  string N;
  cin >> N;
  string tmp;
  tmp += N.at(0);
  rep(i, N.size() - 1)
  {
    tmp += "9";
  }
  ll ans;
  if (tmp == N)
  {
    ans = ((N.at(0) - '0') + (N.size() - 1) * 9);
  }
  else
  {
    ans = ((N.at(0) - '0') + (N.size() - 1) * 9 - 1);
  }
  cout << ans << endl;
  return 0;
}