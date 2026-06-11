#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  long long n,a,b,c,d,e,f;
  cin>>n>>a>>b>>c>>d>>e;
  f=min({a,b,c,d,e});
  long long ans=ceil((double) n/f)+4;
  cout<<ans<<endl;
  
  
  
  
  }