#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  string t = "keyence";
  if(s == t){
    cout << "YES" << endl;
    return 0;
  }
  
  int l = s.size();
  bool ok = false;
  for(int i = 0; i < l; i++){
    for(int j = i; j < l; j++){
      string ans = "";
      for(int k = 0; k < l; k++){
        if(k >= i && k <= j) continue;
        ans += s.at(k);
      }
      if(ans == t) ok = true;
    }
  }
  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}