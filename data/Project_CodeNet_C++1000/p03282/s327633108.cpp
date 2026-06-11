#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int k;cin>>k;
  char res;
  int cnt=0;
  for(auto& val:s){
    ++cnt;
    if(cnt==k){
      res=val;
      break;
    }
    if(val!='1'){
      res=val;
      break;
    }
  }
  cout<<res<<endl;
  return 0;
}
