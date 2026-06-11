#include<bits/stdc++.h>
#include <vector>

using namespace std;

 int main(){

  int n,m;
  cin>>n>>m;

  int lmax=0,rmin=100000;

  for(int i=0;i<m;i++){
    int l,r; cin>>l>>r;
    lmax = max(lmax,l);
    rmin = min(rmin,r);
  }

  int ans = rmin-lmax+1;

  if(ans < 0)
    cout<<"0"<<endl;
  else
    cout<<ans<<endl;


return 0;
 }