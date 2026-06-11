#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  if(s.size()<8){
    cout<<"YES"<<endl;
    return 0;
  }
  int win=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='o') win++;
  }
  if(win+(15-s.size())<8){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
}