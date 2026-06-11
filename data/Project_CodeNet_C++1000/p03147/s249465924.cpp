#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;cin>>n;
  bool f=true,ff=false;
  vector<int> x(n+1);
  for(int i=1;i<=n;++i)cin>>x[i];

  while(f){
    f=false;
    for(int i=n;i>0;--i){
      if(x[i]!=0&&x[i-1]==0)c++;
      x[i]=max(0,x[i]-1);
    }
    for(int i=1;i<=n;++i){
      if(x[i]!=0)f=true;
    }
  }
  cout<<c;
}