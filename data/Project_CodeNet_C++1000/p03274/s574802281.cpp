#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k,i,d,ans;
  cin>>n>>k;
  vector<int64_t> x(n);
  for(i=0;i<n;i++) cin>>x.at(i);
  for(i=0;i<=n-k;i++){
    if(x.at(i)*x.at(i+k-1)>=0) d=max(abs(x.at(i)),abs(x.at(i+k-1)));
    else d=x.at(i+k-1)-x.at(i)+min(-x.at(i),x.at(i+k-1));
    if(i==0||d<ans) ans=d;
  }
  cout<<ans<<endl;
}