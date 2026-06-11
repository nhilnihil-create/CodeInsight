#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  long long int n, m; cin >> n >> m;
  long long int ans;
  if(n >= 2 && m >= 2) ans = (n - 2) * (m - 2);
  else if(n == 1 && m == 1) ans = 1;
  else ans = max(n, m) - 2;
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
