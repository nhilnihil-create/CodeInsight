#include <bits/stdc++.h>
using namespace std;
string rotate(string s){
  return s.substr(1)+s[0];
}
int main(){
  string s,t;
  cin>>s>>t;
  int cnt=0;
  int n=s.length();
  for(int i=0;i<n;i++){
    if(s==t){
      cnt++;
    }
    else{
      s=rotate(s);
    }
  }
  if(cnt>0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}