#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  string s;
  cin >> a >> b >> s;
  string res = "Yes";
  if(s.length() != a+b+1){
    res = "No";
  }
  for(int i = 0; i < s.length(); ++i){
    if(i == a){
      if(s[i] != '-'){
        res = "No";
      }
    }else{
      if(!isdigit(s[i])){
        res = "No";
      }
    }
  }
  cout << res;
}