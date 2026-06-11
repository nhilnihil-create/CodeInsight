#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,M,ans=-1; cin>>N>>M;
  string s,t; cin>>s>>t;
  long long L, a=N, b=M, c=a%b;
  while(c!=0){
    a=b, b=c, c=a%b;
  }
  L=N*M/b;
  int x=L/N, y=L/M, z=N/y;
  for(int i=0; i<z; i++){
    if(s[i*y]!=t[i*x]) break;
    if(i==z-1) ans=L;
  }
  cout<<ans<<endl;
}