#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,t,si;
  int ss,ts;
  cin>>si>>t;
  ss=si.size();
  ts=t.size();
  vector<string>ans;
  bool ok;
  if(ts>ss){
      cout<<"UNRESTORABLE";
      return 0;
  }
  for(int i=ts;i<=ss;i++){
      ok=true;
      s=si;
      for(int j=0;j<ts;j++){
          if(s.at(ss-i+j)=='?'||s.at(ss-i+j)==t.at(j))continue;
          ok=false;
      }
      if(!ok)continue;
      for(int j=0;j<ts;j++){
          s.at(ss-i+j)=t.at(j);
      }
      for(int i=0;i<ss;i++){
        if(s.at(i)=='?')s.at(i)='a';
      }  
      ans.push_back(s);
  }
  if(ans.size()==0)cout<<"UNRESTORABLE";
  else{
    sort(ans.begin(),ans.end());
    cout<<ans.at(0);
  } 
}