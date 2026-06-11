#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int l = s.size();
  for(int i = 0; i < 26; i++){
    char now = 'a' + i;
    bool ok = true;
    for(int j = 0; j < l; j++) if(now == s.at(j)) ok = false;
    if(ok){
      cout << s << now << endl;
      return 0;
    }
  }
  
  vector<char> ans(1, s.at(l-1));
  for(int i = l-1; i > 0; i--){
    if(s.at(i) < s.at(i-1)) ans.push_back(s.at(i-1));
    else{
      for(int j = 0; j < i-1; j++) cout << s.at(j);
      sort(ans.begin(), ans.end());
      char c;
      for(auto a : ans){
        if(a > s.at(i-1)){
          c = a;
          break;
        }
      }
      cout << c << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
}