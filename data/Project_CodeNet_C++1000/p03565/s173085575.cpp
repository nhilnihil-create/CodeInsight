#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s,t,u;
  cin >> s >> t;
  int i,j;
  bool is=true,no=false;
  string ans;
  for(i=0;i<s.size();i++){
    ans+='z';
  }
  for(i=0;i<s.size()-t.size()+1;i++){
    u=s;
    is=true;
    for(j=0;j<t.size();j++){
      if(u.at(i+j)=='?'){
        u.at(i+j)=t.at(j);
      }
    }
    for(j=0;j<t.size();j++){
      if(t.at(j)!=u.at(i+j)){
        is=false;
      }
    }
    if(is){
      no=true;
      for(int k=0;k<s.size();k++){
        if(u.at(k)=='?'){
          u.at(k)='a';
        }
      }
      if(ans>u){
        ans=u;
      }
    }
  }
  if(no){
    cout << ans;
  }else{
    cout << "UNRESTORABLE";
  }
}