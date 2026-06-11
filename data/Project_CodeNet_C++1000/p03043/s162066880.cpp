#include<bits/stdc++.h>
using namespace std;
main(){
  int n,k;cin>>n>>k;
  long double ans=0;
  for(int i=1;i<=n;i++){
    int j=i;
    int cnt=0;
    while(j<k){
      j*=2;
      cnt++;
    }
    ans+=1.0/pow(2,cnt);
  }
  ans/=n;
  cout<<fixed<<setprecision(15)<<ans<<'\n';
}
    
    
    