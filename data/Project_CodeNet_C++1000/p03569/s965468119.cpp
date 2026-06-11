#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s,c;
  int sum=0,r,l=0;
  bool f=true;
  cin>>s;
  r=s.size()-1;
  for(int i=0;i<s.size();i++){
    if(s[i]!='x') c+=s[i];
  }
  int o=0,p=c.size()-1;
  while(o<p){
    if(c[o]!=c[p]){
      f=false;
      break;
    }
    o++;
    p--;
  }
  if(f){
    while(l<r){
      if(s[l]!=s[r]){
        if(s[l]=='x') sum++;
        else l--;
        if(s[r]=='x') sum++;
        else r++;
      }
      l++,r--;
    }
  }
  if(f) cout<<sum<<"\n";
  else cout<<"-1\n";
}