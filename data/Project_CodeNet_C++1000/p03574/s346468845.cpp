#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  char c[h][w];
  int a[h][w];
  rep(i, h){
    rep(j, w){
      cin >> c[i][j];
      a[i][j]= 0;
    }
  }
  
  rep(i, h){
    rep(j, w){
      if(i != 0 && j != 0 && c[i - 1][j - 1] == '#') a[i][j]++;
      if(i != 0 && c[i - 1][j] == '#') a[i][j]++;
      if(i != 0 && j != w - 1 && c[i - 1][j + 1] == '#') a[i][j]++;
      if(j != w - 1 && c[i][j + 1] == '#') a[i][j]++;
      if(i != h - 1 && j != w - 1 && c[i + 1][j + 1] == '#') a[i][j]++;
      if(i != h - 1 && c[i + 1][j] == '#') a[i][j]++;
      if(i != h - 1 && j != 0 && c[i + 1][j - 1] == '#') a[i][j]++;
      if(j != 0 && c[i][j - 1] == '#') a[i][j]++;
    }
  }
  
  rep(i, h){
    rep(j, w){
      if(c[i][j] == '#') cout << c[i][j];
      else cout << a[i][j];
    }
    cout << endl;
  }
  //cout << ans << endl;

  return 0;
}
