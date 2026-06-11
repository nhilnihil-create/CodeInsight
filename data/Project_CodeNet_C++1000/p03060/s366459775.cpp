#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  int ans = 0;
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];
  rep(i, n) ans += max(0, v[i] - c[i]);
  cout << ans << endl;
  
  return 0;
}