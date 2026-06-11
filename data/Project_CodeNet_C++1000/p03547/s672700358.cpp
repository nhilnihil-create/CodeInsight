#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;


void solve(){
  string x, y; cin >> x >> y;
  if(x < y) cout << "<\n";
  else if(x > y) cout << ">\n";
  else cout << "=\n";
  return;
}

int main(){
  solve();
  return 0;
}
