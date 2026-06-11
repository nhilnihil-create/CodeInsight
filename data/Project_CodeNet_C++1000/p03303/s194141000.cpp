#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n;
  string s;
  cin>>s>>n;
  for(int i=0;i<s.size();i+=n){
    cout<<s[i];
  }
  cout<<"\n";
}