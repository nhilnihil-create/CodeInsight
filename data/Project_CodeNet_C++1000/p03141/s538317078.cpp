#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  vector<pair<ll,ll>> vec(n);
  for(auto&& e: vec) 
  {
    cin>>e.first>>e.second;
  }
  sort(vec.begin(), vec.end(),[](auto a,auto b){
    return (a.first+a.second)>(b.first+b.second);
  });
  
  ll takahasi=0,aoki=0;
  for (int i = 0; i < n; ++i)
  {
    if(i%2==0) takahasi+=vec[i].first;
    else aoki+=vec[i].second;
  }
  cout<<takahasi-aoki<<endl;

}