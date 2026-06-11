#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  vector<int> a(3);
  for(int i = 0; i < 3; i++) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int ans = 0;
  for(int i = 1; i < 3; i++){
    ans += a[i - 1] - a[i];
  }
  cout << ans << endl;
  return;
}
int main(){
  solve();
  return 0;
}
