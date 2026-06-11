#include <bits/stdc++.h>
using namespace std;

int main(){
  long long  N;
  cin>>N;
  vector<long long> a(N),b(N);
  for(long long i=0;i<N;i++) cin>>a[i]>>b[i];
 
  using P = pair<long long,long long>;
  vector<P> vp;
  for(long long i=0;i<N;i++) vp.emplace_back(a[i]+b[i],i);
 
  sort(vp.rbegin(),vp.rend());
  long long ans=0;
  for(long long i=0;i<N;i++){
    if(i%2==0) ans+=a[vp[i].second];
    else ans-=b[vp[i].second];
  }
  cout<<ans<<endl;
  return 0;
}