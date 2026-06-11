#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int f=0, b=S.size()-1;
  int ans =0;
  while(f<b){
    if(S[f]==S[b]){
      f++; b--;
    }
    else if(S[f]=='x'){
      f++;
      ans++;
    }else if(S[b]=='x'){
      b--;
      ans++;
    }else{
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}