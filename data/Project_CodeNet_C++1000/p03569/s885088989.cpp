#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;cin >> s;
  int l_p = 0;
  int r_p = int(s.size()) -1;
  int ans = 0;
  if(s.size()==1){
    cout << 0 << endl;
    return 0;
  }
  while(true){
    if(s.at(l_p)==s.at(r_p)){
      l_p++;
      r_p--;
    }else if(s.at(l_p)=='x'){
      ans++;
      l_p++;
    }else if(s.at(r_p)=='x'){
      ans++;
      r_p--;
    }else{
      cout << -1 << endl;
      return 0;
    }
    if(r_p<=l_p){
      cout << ans << endl;
      return 0;
    }
  }
}

        