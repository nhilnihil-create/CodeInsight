#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N,K; cin>>N>>K;
  vector<ll> vecA(N);
  rep(i,N)
  {
    cin>>vecA.at(i);
  }
  sort(vecA.begin(),vecA.end());
  vector<ll> veckosu(0);
  rep(i,N)
  {
    if(i==0) {veckosu.push_back(1); continue;}
    if(vecA.at(i)==vecA.at(i-1)) {veckosu.at(veckosu.size()-1)++; continue;}
    veckosu.push_back(1);
  }
  sort(veckosu.begin(),veckosu.end());
  if(veckosu.size()<=K) {cout<<0<<endl; return 0;}
  ll count=0;
  rep(i,veckosu.size()-K)
  {
    count+=veckosu.at(i);
  }
  cout<<count<<endl;
  return 0;
}