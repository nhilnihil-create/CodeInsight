#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int l=0;
  int r=s.size()-1;
  int ans=0;
  while(true){
    if(l>r){
      break;
    }
    if(s.at(l)==s.at(r)){
      l++;
      r--;
    }else if(s.at(l)=='x'){
      ans++;
      l++;
    }else if(s.at(r)=='x'){
      ans++;
      r--;
    }else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
