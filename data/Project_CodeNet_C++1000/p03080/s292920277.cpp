#include<bits/stdc++.h> 
using namespace std;
int main(){
 string s; 
 int n, R=0,B=0;
cin>>n;
 cin>>s; 
for(int i=0;i<n;i++){ 
if(s[i]=='R') R++; 
else if(s[i]=='B') B++;} 
if(R>B) cout<<"Yes"<<endl; else if(R<=B) cout<<"No"<<endl; } 
  