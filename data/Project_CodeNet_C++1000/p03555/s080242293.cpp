#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;


void solve(){
  string s, t; cin >> s >> t;
  reverse(t.begin(), t.end());
  if(s == t) cout << "YES\n";
  else cout << "NO\n";
  return;
}

int main(){
  solve();
  return 0;
}
