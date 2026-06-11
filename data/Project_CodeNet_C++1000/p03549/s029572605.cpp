#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,ans;
  cin>>n>>m;
  ans=100*n+1800*m;
  for(i=0;i<m;i++) ans*=2;
  cout<<ans<<endl;
}