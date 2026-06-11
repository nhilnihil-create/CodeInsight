#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t="AKIHABARA"; cin>>s;
  int n=s.size(), i=0, j=0;
  
  while(i<9){
    if(j<n && t[i]==s[j]){++i; ++j;}
    else if(t[i]=='A')++i;
    else break;
  }

  if(i==9 && j==n)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
