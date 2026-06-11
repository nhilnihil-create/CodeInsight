#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;cin>>n;
  string s;
cin>>s;
  int ci=0,cj=0;
  for(char ch:s){
      if(ch=='R') ci++;
       else cj++;
  }
  if(ci>cj) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
