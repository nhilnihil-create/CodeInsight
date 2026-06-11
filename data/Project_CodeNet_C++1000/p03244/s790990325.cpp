#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

signed main(){

  int n;
  cin>>n;
  vector<ll> a(n);
  for(auto& ai:a)cin>>ai;

  map<ll,ll> odd,eve;
  for(int i=0;i<n;++i){
    if(i&1)odd[a[i]]++;
    else eve[a[i]]++;
  }

  using pll = pair<ll,ll>;
  vector<pll> a_odd,a_eve;
  for(auto x:odd)a_odd.emplace_back(x);
  for(auto x:eve)a_eve.emplace_back(x);
  auto cmp = [](pll a,pll b){return a.second>b.second;};
  sort(begin(a_odd),end(a_odd),cmp);
  sort(begin(a_eve),end(a_eve),cmp);

  if(a_odd[0].first!=a_eve[0].first){
    cout<< n-a_odd[0].second-a_eve[0].second <<endl;
  }else{
    if(a_odd.size()==1&&a_eve.size()==1){
      cout<< n-max(a_odd[0].second,a_eve[0].second) <<endl;
    }
    else if(a_odd.size()==1){
      cout<< n-a_odd[0].second-a_eve[1].second <<endl;
    }
    else if(a_eve.size()==1){
      cout<< n-a_odd[1].second-a_eve[0].second <<endl;
    }
    else{
      ll tmp1 = a_odd[0].second+a_eve[1].second;
      ll tmp2 = a_odd[1].second+a_eve[0].second;
      cout<< min(n-tmp1,n-tmp2) <<endl;
    }
  }

}