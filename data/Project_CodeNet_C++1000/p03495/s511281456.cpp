#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll N,K;cin>>N>>K;
  vector<ll> A(N+1);
  map<ll,ll> m;
  for (ll i=1;i<=N;i++)
  {
    cin>>A[i];
    m[A[i]]++;
  }
  //cout<<K-(m.size())<<endl;
  ll msize=m.size();

  if( K - msize > 0)
  {
    //cout<<K - msize<<endl;
    cout<<0<<endl;
    return (0);
  }
  
  vector<ll> g;
  for (auto i=m.begin();i!=m.end();i++)
  {
    //cout<<"m["<<i->first<<"]="<<i->second<<endl;
    g.push_back(i->second);
  }
  
  sort(g.begin(),g.end());
  
  //for (ll i=0;i<g.size();i++)
    //cout<<"g["<<i<<"]="<<g[i]<<endl;
  
  ll count=0;
  for (ll i=0;i<m.size()-K;i++)
  {
    count += g[i]; 
  }
  
  cout<<count<<endl;
}