#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int N,T;
 cin>>N>>T;
 vector<int>c(N);
 vector<int>t(N);
 int ans=99999;
  
 for(int i=0;i<N;i++){
   cin>>c[i]>>t[i];}
  
 for(int i=0;i<N;i++){
   if(t[i]<=T&&c[i]<=ans){ans=c[i];}
 }
  
  if(ans==99999){cout<<"TLE"<<endl;}
  else{cout<<ans<<endl;}
 
 return 0;}