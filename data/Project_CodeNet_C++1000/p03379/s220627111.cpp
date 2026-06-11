#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  vector<pair<ll,ll>> vecX(N);
  rep(i,N)
  {
    cin>>vecX.at(i).first;
    vecX.at(i).second=i;
  }
  sort(vecX.begin(),vecX.end());
  map<ll,ll> mapX;
  rep(i,N)
  {
    if(i<N/2) {mapX[vecX.at(i).second]=vecX.at(N/2).first; continue;}
    mapX[vecX.at(i).second]=vecX.at(N/2-1).first;
  }  
  rep(i,N)
  {
    cout<<mapX.at(i)<<endl;
  }  
  return 0;
}