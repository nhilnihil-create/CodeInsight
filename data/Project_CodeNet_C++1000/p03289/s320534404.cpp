#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s;
  cin >> s;
  string ans="AC";
  if(s.at(0)!='A'){
    ans="WA";
  }
  ll is=0;
  for(int i=2;i<s.size()-1;i++){
    if(s.at(i)=='C'){
      is++;
    }
  }
  if(is!=1){
    ans="WA";
  }
  for(int i=1;i<s.size();i++){
    if(s.at(i)=='C'){
      continue;
    }
    if(!(s.at(i)>='a' && s.at(i)<='z')){
      ans="WA";
    }
  }
  cout << ans;
}