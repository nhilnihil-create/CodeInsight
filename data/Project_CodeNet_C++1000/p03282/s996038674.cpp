#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  ll k;
  cin >> s >> k;
  
  int i,n;
  for(i=0;i<s.size();i++){
    if(s.at(i)!='1') break;
  }
  
  if(i<k) cout << s.at(i) << endl;
  else cout << 1 << endl;
  
}