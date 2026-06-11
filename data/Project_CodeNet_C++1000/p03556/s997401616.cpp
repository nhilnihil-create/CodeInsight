#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;


void solve(){
  int n; cin >> n;
  int i;
  for(i = 1; i < 100000; i++){
    if(i * i > n) break;
  }
  cout << (i - 1) * (i - 1) << endl;
  return;
}

int main(){
  solve();
  return 0;
}
