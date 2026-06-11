#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  string s;
  ll k,count=0;
  cin >> s >> k;
  rep(i,100){
    if(s[i]=='1') count++;
    if(s[i]!='1') break;
  }
  
  if(k>count){
    rep(i,100){
      if(s[i]!='1'){
       cout << s[i] << endl;
       return 0;
      }
    }
  }
  
  if(k<=count) cout << 1 << endl;
  
  return 0;
}
