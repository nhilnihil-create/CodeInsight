#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  int ans = s.size();
  for(int i = 1; i < s.size(); i++){
    if(s.at(i - 1) != s.at(i)){
      ans = min(ans, max(i, (int) s.size() - i));
    }
  }
  
  cout << ans << '\n';
}