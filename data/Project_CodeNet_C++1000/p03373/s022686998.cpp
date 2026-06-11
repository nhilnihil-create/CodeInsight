#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  vector<int> v(3);

  v[0] = a * x + b * y;
  if (x < y){
    v[1] = c * 2 * x + b * (y - x);
    v[2] = c * 2 * y;
  } else {
    v[1] = c * 2 * y + a * (x - y);
    v[2] = c * 2 * x;
  }
  int ans = 4e9;
  rep(i, 3){
    if (v[i] < ans) ans = v[i];
  }
  cout << ans << endl;

  return 0;
}