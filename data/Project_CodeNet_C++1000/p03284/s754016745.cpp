#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int n, k; cin >> n >> k;
  if(n % k == 0) cout << 0 << endl;
  else cout << 1 << endl;
  return;
}
int main(){
  solve();
  return 0;
}
