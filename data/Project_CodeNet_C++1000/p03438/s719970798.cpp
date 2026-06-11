#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int n;
  cin>>n;
  vector<int> a(n),b(n);
  for(auto& ai:a)cin>>ai;
  for(auto& bi:b)cin>>bi;

  ll asum = accumulate(begin(a),end(a),0ll);
  ll bsum = accumulate(begin(b),end(b),0ll);
  ll k = bsum-asum;

  ll as = 0,bs = 0;
  auto ceil = [](auto a,auto b){return (a-1)/b+1;};
  rep(i,n){
    if(a[i]>b[i]){
      bs += a[i]-b[i];
    }
    if(a[i]<b[i]){
      as += ceil(b[i]-a[i],2ll);
    }
  }
  if(as<=k&&bs<=k)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

}