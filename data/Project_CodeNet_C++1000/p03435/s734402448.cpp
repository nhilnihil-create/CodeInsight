#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int a[3][3];
  rep(i, 3){
    rep(j, 3) cin >> a[i][j];
  }
  int x[3], y[3];
  string s = "Yes";
  x[0] = 0;
  rep(i, 3) y[i] = a[0][i] - x[0];
  rep(i, 3) x[i] = a[i][0] - y[0];
  rep(i, 3){
    rep(j, 3){
      if(x[i] + y[j] != a[i][j]) s = "No";
    }
  }
  cout << s << endl;
       

  return 0;
}