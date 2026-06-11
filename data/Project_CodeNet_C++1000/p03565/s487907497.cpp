#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  int sn=s.size();
  int tn=t.size();
  map<string,int>mp;
  string kotae;
  if(sn<tn){
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  for(int i=0;i<sn-tn+1;i++){
    bool hantei=true;
    for(int j=0;j<tn;j++){
      if(s[i+j]==t[j]||s[i+j]=='?')continue;
      else {
        hantei=false;
        break;
      }
    }
    if(hantei){
      //cout<<"i"<<i<<endl;
      for(int k=0;k<i;k++){
        if(s[k]=='?')kotae.push_back('a');
        else kotae.push_back(s[k]);
      }
      for(int k=0;k<tn;k++){
        kotae.push_back(t[k]);
      }
      if(i+tn<sn){
        for(int k=i+tn;k<sn;k++){
          if(s[k]=='?')kotae.push_back('a');
          else kotae.push_back(s[k]);
        }
      }
      mp[kotae]++;
      kotae.clear();
    }
  }
  if(mp.size()>0){
    auto begin=mp.begin(),end=mp.end();
    for(auto iter=begin;iter!=end;iter++){
      string a=iter->first;
      cout<<a<<endl;
      return 0;
    }
  }else{
    cout<<"UNRESTORABLE"<<endl;
  }
  return 0;
}


