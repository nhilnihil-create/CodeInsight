#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  unsigned long long int x, y; cin >> x >> y;
  y /= x;
  x /= x;
  unsigned long long int sum = 0;
  while(x <= y){
    x *= 2;
    sum++;
  }
  cout << sum << endl;
  return;
}

int main(){
  solve();
  return 0;
}
