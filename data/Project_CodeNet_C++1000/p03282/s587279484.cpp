#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll k;
  string s;
  cin >> s >> k;
  if(k<=s.size()){
    bool is=true;
    rep(i,k){
      if(s.at(i)!='1'){
        is=false;
      }
    }
    if(is){
      cout << 1;
      return 0;
    }
  }
  rep(i,s.size()){
    if(s.at(i)!='1'){
      cout<< s.at(i);
      return 0;
    }
  }
}
    