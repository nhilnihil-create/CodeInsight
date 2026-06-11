#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int D;
  cin >> D;
  
  string ans = "Christmas";
  
  if(D<=24) ans += " Eve";
  if(D<=23) ans += " Eve";
  if(D<=22) ans += " Eve";
  
  cout << ans << endl;
  return 0;
}