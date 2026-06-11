#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>t(n+1),x(n+1),y(n+1);
  t[0]=x[0]=y[0]=0;
  for(int i=1;i<=n;i++){
    cin>>t[i]>>x[i]>>y[i];
  }
  bool at=true;
  for(int i=0;i<n;i++){
    int dist=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
    int d=t[i+1]-t[i];
    if(d<dist) at=false;
    if(dist%2!=d%2) at=false;
  }
  if(at) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
    
  
