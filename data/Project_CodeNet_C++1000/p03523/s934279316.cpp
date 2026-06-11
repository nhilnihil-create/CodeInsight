#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,base="AKIHABARA"; cin>>s;
  if(s.size()>base.size()){
    cout<<"NO"<<endl;
    return 0;
  }string renew="";
  int now=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!=base[now] && base[now]=='A'){
      renew+='A';
      renew+=s[i];
      now++;
    }else{
      renew+=s[i];
    }
    now++;
  }
  if(now==8){
    renew+='A';
  }
  if(renew==base){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}