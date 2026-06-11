#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << "-1\n";
    return 0;
  }
  
  vector<bool> x(26, false);
  if(s.size() < 26){
    for(int i = 0; i < s.size(); i++){
      x.at(s.at(i) - 'a') = true;
    }
    cout << s;
    for(int i = 0; i < 26; i++){
      if(x.at(i) == false){
        cout << (char) (i + 'a') << '\n';
        return 0;
      }
    }
  }
  
  string t = s;
  for(int i = 25; i >= 0; i--){
    x.at(t.at(i) - 'a') = true;
    for (int j = t.at(i) - 'a' + 1; j < 26; j++) {
      if (x.at(j) == true) {
        t.at(i) = j + 'a';
        cout << t << '\n';
        return 0;
      }
    }
    t.pop_back();
  }
}