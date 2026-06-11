#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <cstdlib>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  if(b % a == 0) cout << a + b << endl;
  else cout << b - a << endl;
  return;
}

int main(){
  solve();
  return 0;
}
