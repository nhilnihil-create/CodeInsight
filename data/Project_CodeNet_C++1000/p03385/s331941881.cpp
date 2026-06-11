#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;


void solve(){
  string s; cin >> s;
  sort(s.begin(), s.end());
  if(s == "abc") cout << "Yes\n";
  else cout << "No\n";
  return;
}

int main(){
  solve();
  return 0;
}
