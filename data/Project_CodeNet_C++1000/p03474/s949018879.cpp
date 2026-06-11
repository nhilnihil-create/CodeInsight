#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b; cin>>a>>b;
  string s; cin>>s;
  bool ans=true;
  if(s.length()!=a+b+1) ans=false;
  if(ans){
    string sb=s.substr(0,a);
    for(char c:sb){
      if('0'>c||c>'9'){
        ans=false; break;
      }
    }
  }
  if(ans){
    if(s.substr(a,1)!="-") ans=false;      
  }
  if(ans){
    string sb=s.substr(a+1,b);
    for(char c:sb){
      if('0'>c||c>'9'){
        ans=false; break;
      }
    }
  }
  cout<<(ans?"Yes":"No");
}