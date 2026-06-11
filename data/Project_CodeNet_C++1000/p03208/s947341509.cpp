#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,i,ans=1e9;
  cin>>n>>k;
  vector<int> h(n);
  for(i=0;i<n;i++) cin>>h.at(i);
  sort(h.begin(),h.end());
  for(i=0;i<=n-k;i++) if(h.at(i+k-1)-h.at(i)<ans) ans=h.at(i+k-1)-h.at(i);
  cout<<ans<<endl;
}