#include <bits/stdc++.h>
using namespace std;
int ma;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='o')ma++;
  }
  if(ma+15-s.size()>=8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}