#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  string akiba = "AKIHABARA";
  for(int i = (1 << 9)-1; i >= 0; --i){
    bool ok = true;
    string t;
    for(int j = 0; j < 9; ++j){
      if((1<<j)&i){
        t += akiba[j];
      }else{
        ok &= akiba[j] == 'A';
      }
    }
    if(ok && t == s){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}