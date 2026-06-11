#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s,t;
  cin>>s>>t;
  for(int i=s.size()-1; i>=0; i--){
    bool tf=true;
    for(int j=t.size()-1; j>=0;j--){
      if(t[j]==s[i-t.size()+1+j] || s[i-t.size()+1+j]=='?'){
        
      }else{
        tf=false;
        break;
      }
    }
    if(tf){
      for(int j=0;j+t.size()<i+1;j++){
        cout<<(s[j]=='?' ? 'a' : s[j]);
      }
      cout<<t;
      for(int j=i+1;j<s.size();j++){
        cout<<(s[j]=='?' ? 'a' : s[j]);
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<"UNRESTORABLE"<<endl;
  return 0;
}