#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<bool>alpha(26,true);
  for(int i = 0;i < s.size();i++) alpha[s[i]-'a'] = false;
  if(s.size() != 26){
    for(int i = 0;i < 26;i++){
      if(alpha[i]){
        s.push_back('a'+i);
        break;
      }
    }
    cout << s << endl;
    return 0;
  }
  else if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  else{
    for(int i = 25;i > 0;i--){
      if(s[i] < s[i-1]){
        alpha[s[i]-'a'] = true;
        s.pop_back();
      }
      else{
        alpha[s[i]-'a'] = true;
        s.pop_back();
        char t = s[s.size()-1];
        s.pop_back();
        for(int j = 0;j < 26;j++){
          if(alpha[j] && t-'a' < j){
            s.push_back('a'+j);
            break;
          }
        }
        cout << s << endl;
        return 0;
      }
    }
  }
}