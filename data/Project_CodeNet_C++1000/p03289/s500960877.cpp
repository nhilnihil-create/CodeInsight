#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ll long long
#define ld long double

int main(){
  string s;
  cin >> s;
  
  bool flag = true;
  
  if(s[0] != 'A') flag = false;
  
  ll Cidx = 0;
  string sub = s.substr(2,s.size()-3);
  if(count(sub.begin(),sub.end(),'C')!=1) flag = false;
  
  if(!flag){
    cout << "WA" << endl;
    return 0;
  }
  
  //ちょっとコード汚いけれど、大文字Cが１文字確定しているので以下のif文が通る
  for(ll i=1; i<=s.size(); i++){
    if(s[i]!='C' && isupper(s[i])) flag = false;
  }
  
  if(flag) cout << "AC" << endl;
  else cout << "WA" << endl;
}