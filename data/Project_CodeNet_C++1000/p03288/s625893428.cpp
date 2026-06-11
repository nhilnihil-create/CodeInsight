#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int r; cin >> r;
  if(r < 1200) cout << "ABC\n";
  else if(r < 2800) cout << "ARC\n";
  else cout << "AGC\n";
  return;
}
int main(){
  solve();
  return 0;
}
