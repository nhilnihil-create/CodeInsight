#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <cstdlib>

using namespace std;

int gcd(int x, int y){
  int r = x % y;
  while(r != 0){
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}

void solve(){
  double t, x; cin >> t >> x;
  cout << t / x << endl;
  return;
}

int main(){
  solve();
  return 0;
}
