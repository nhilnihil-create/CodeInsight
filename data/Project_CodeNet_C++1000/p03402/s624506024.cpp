#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int a, b;
  cin >> a >> b;
  a--; b--;
  
  const int maxh = 100, maxw = 100;
  vector<vector<char>> ans(maxh, vector<char>(maxw, '.'));
  rep(i, maxh/2) rep(j, maxw) ans[i][j] = '#';
  
  for(int i = 0; i < maxh/2; ++++i)
  {
    for(int j = 0; j < maxw; ++++j)
    {
      if(a == 0) break;
      ans[i][j] = '.';
      a--;
    }
    if(a == 0) break;
  }
  
  for(int i = maxh-1; i > maxh/2; ----i)
  {
    for(int j = 0; j < maxw; ++++j)
    {
      if(b == 0) break;
      ans[i][j] = '#';
      b--;
    }
    if(b == 0) break;
  }
  
  cout << maxh << " " << maxw << "\n";
  rep(i, maxh)
  {
    rep(j, maxw) cout << ans[i][j];
    cout << "\n";
  }
  
  
  return 0;
}