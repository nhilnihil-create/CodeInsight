#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  string s,t,u; cin>>s>>t>>u;
  int sum=0;
  for(int i=0;i<n;i++){
    if(s[i]!=t[i] && t[i]==u[i] && s[i]==u[i]) sum++;
    if(s[i]==t[i] && t[i]!=u[i] && s[i]==u[i]) sum++;
    if(s[i]==t[i] && t[i]==u[i] && s[i]!=u[i]) sum++;
    if(s[i]!=t[i] && t[i]!=u[i] && s[i]==u[i]) sum++;
    if(s[i]!=t[i] && t[i]==u[i] && s[i]!=u[i]) sum++;
    if(s[i]==t[i] && t[i]!=u[i] && s[i]!=u[i]) sum++;
    if(s[i]!=t[i] && t[i]!=u[i] && s[i]!=u[i]) sum+=2;
  }
  cout<<sum<<endl;
}

    
  
