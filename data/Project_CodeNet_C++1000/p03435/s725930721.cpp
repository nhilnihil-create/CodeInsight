#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> c[i][j];
  
  
  if(c[0][2]+c[1][0]-c[0][0] != c[1][2]) {
    cout << "No" << endl;
    return 0;
  }
  if(c[2][0]+c[1][1]-c[1][0] != c[2][1]) {
    cout << "No" << endl;
    return 0;
  }
  if(c[0][2]+c[2][0]-c[0][0] != c[2][2]) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
