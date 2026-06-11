#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  string s,t,copy;
  cin>>s>>t;
  if(s.size()<t.size()){
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  for(int i=s.size()-t.size();i>=0;i--){
    copy=s.substr(i,t.size());
    int x=0;
    for(int j=0;j<copy.size();j++){
      if(copy[j]!='?'&&copy[j]!=t[j]){
        x++;
      }
    }
    if(x==0){
      for(int j=0;j<s.size();j++){
        if(j>=i&&j<i+t.size()){
          s[j]=t[j-i];
        }
      }
      for(int j=0;j<s.size();j++){
        if(s[j]=='?'){
          cout<<'a';
        }
        else{
          cout<<s[j];
        }
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<"UNRESTORABLE"<<endl;
}