#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void solve(){
  int d; cin >> d;
  string s = "Christmas";
  for(int i = d; i < 25; i++){
    s += " Eve";
  }
  cout << s << endl;
  return;
}

int main(){
  solve();
  return 0;
}
