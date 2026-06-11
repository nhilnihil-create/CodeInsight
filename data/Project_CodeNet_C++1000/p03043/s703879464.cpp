#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  int n,k;
  cin>>n>>k;
  double ans=0;
  for(int i=1;i<=n;i++){
    double d=1.0/n;
    for(int c=i;c<k;c*=2) d*=0.5;
    ans+=d;
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
}