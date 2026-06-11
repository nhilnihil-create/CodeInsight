#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  int a, b, x; cin >> a >> b >> x;
  if(x >= a && x <= a + b) cout << "YES\n";
  else cout << "NO\n";
  return;
}

int main(){
  solve();
  return 0;
}
