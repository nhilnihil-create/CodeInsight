#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  string n;
  cin>>n;
  int ans=0;
  if(n[0]=='2') ans+=1;
  if(n[1]=='2') ans+=1;
  if(n[2]=='2') ans+=1;
  if(n[3]=='2') ans+=1;
  cout<<ans;

} 