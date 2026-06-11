#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m-1);
  rep(i, m) cin >> x[i];
  sort(x.begin(), x.end());
  rep(i, m-1) y[i] = x[i+1] - x[i];
  sort(y.begin(), y.end());
  int l = max(0, m-n);
  int ans = 0;
  rep(i, l) ans += y[i];
  cout << ans << endl;
  
  return 0;
}