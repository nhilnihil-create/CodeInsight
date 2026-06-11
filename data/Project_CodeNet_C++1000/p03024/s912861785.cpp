#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  for(i=0;i<s.size();i++){
    if(s[i]=='x')cnt++;
  }
  if(15-cnt>=8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}