#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s,t;
  cin >> s >> t;
  int l = s.size();
  int m = t.size();
  int res = -1;
  for(int i = 0; i <= (l - m); ++i){
    bool flag = true;
    for(int j = 0; j < m; ++j){
      if(s[i+j] == t[j] || s[i+j] == '?'){
        continue;
      }else{
        flag = false;
      }
    }
    if(flag){
      res = i;
    }
  }
  if(res != -1){
    string ans = s;
    for(int i = res; i < res + m; ++i){
      ans[i] = t[i-res];
    }
    for(int i = 0; i < l; ++i){
      if(ans[i] == '?') ans[i] = 'a';
    }
    cout << ans << endl;
  }else{
    cout << "UNRESTORABLE" << endl;
  }
}