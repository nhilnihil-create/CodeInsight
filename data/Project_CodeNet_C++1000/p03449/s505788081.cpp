#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  vector<int> a[2], s[2];
  rep(i,2){
    a[i] = vector<int>(n);
    s[i] = vector<int>(n);
    rep(j,n) cin >> a[i][j];
  }
  s[0][0] = a[0][0];
  rep(j,n-1) s[0][j+1] = s[0][j] + a[0][j+1];
  s[1][n-1] = a[1][n-1];
  rep(j,n-1) s[1][n-1-j-1] = s[1][n-1-j] + a[1][n-1-j-1];
 
  int ans = 0;
  rep(i,n) ans = max(ans,s[0][i]+s[1][i]);
  cout << ans << endl;
}