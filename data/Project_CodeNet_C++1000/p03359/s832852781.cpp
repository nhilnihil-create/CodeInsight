#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  if(b >= a) cout << a << endl;
  else cout << a - 1 << endl;
}

int main(){
  solve();
  //solve2();
  return 0;
}
