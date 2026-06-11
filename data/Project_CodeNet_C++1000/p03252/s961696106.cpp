#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s,t;
  cin >> s >> t;
  int i,j;
  string ans="Yes";
  for(char c='a';c<='z';c++){
    string cp;
    rep(i,s.size()){
     if(s.at(i)==c){
       cp+=t.at(i);
     }
    }
    sort(cp.begin(),cp.end());
    rep(i,cp.size()-1){
      if(cp.at(i)!=cp.at(i+1)){
        ans="No";
      }
    }
  }
  for(char c='a';c<='z';c++){
    string cp;
    rep(i,s.size()){
     if(t.at(i)==c){
       cp+=s.at(i);
     }
    }
    sort(cp.begin(),cp.end());
    rep(i,cp.size()-1){
      if(cp.at(i)!=cp.at(i+1)){
        ans="No";
      }
    }
  }
  cout << ans;
}
      