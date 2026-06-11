#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  int x = b - a;
  int ans = 0;
  for(int i = 1; i <= x - 1; i++){
    ans += i;
  }
  cout << ans - a << endl;
  return;
}
int main(){
  solve();
  return 0;
}
