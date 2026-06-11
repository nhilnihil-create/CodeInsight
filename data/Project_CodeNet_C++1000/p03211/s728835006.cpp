#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  
  int want = 753;
  
  int ans = abs(want - std::stoi(s.substr(0,3)));
  for(int i = 1; i < s.size() - 2; i++){
    int temp = abs(want - std::stoi(s.substr(i,3)));
    if(ans > temp) ans = temp;
  }
  
  cout << ans << endl;
  
  return 0;
}