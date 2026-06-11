#include <iostream>
using namespace std; using P=pair<int,int>; using ll=long long; ll m=1e9+7;

int main() {
  int n; cin>>n;
  ll a[n],b[n]; for(int i=0;i<n;i++) cin>>a[i]>>b[i];
  ll ys=1e18, sm=0; bool all=true;
  for(int i=0;i<n;i++) {
    sm+=a[i];
    if (a[i]>b[i]) ys=min(ys,b[i]);
    if (a[i]!=b[i]) all=false;
  }
  if (all) cout<<"0"<<endl;
  else cout<<sm-ys<<endl;
}