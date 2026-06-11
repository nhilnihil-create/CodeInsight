#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t,u;
  int n,i,j;
  cin>>s>>t;
  n=s.length();
  
  for(i=0;i<n;i++){
    u="";
    for(j=0;j<n;j++) u+=s.at((n-i+j)%n);
    if(t==u) break;
  }
  
  if(i<n) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
