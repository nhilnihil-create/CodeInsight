#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  map<char,ll> mapname;
  mapname['M']=0;
  mapname['A']=0;
  mapname['R']=0;
  mapname['C']=0;
  mapname['H']=0;
  rep(i,N)
  {
    string name; cin>>name;
    if(mapname.count(name.at(0))) {mapname.at(name.at(0))++;}
  }
  vector<ll> vecnum(5);
  ll i=0;
  for(auto p:mapname)
  {
    vecnum.at(i)=p.second;
    i++;
  }
  ll ans=0;
  for(ll i=0;i<5;i++)
  {
    for(ll j=i+1;j<5;j++)
    {
      for(ll k=j+1;k<5;k++)
      {
        ans+=vecnum.at(i)*vecnum.at(j)*vecnum.at(k);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}