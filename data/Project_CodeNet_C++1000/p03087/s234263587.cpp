#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll N,Q; cin>>N>>Q;
  string S; cin>>S;
  vector<ll> kosu(N);
  rep(i,N)
  {
    if(i==0) {kosu.at(0)=0; continue;}
    if(S.substr(i-1,2)=="AC") {kosu.at(i)=kosu.at(i-1)+1; continue;}
    kosu.at(i)=kosu.at(i-1);
  } 
  /*rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<kosu.at(i);
    if(i==N-1) {cout<<endl;}
  } */ 
  rep(i,Q)
  {
    ll l,r; cin>>l>>r;
    l--; r--;
    cout<<kosu.at(r)-kosu.at(l)<<endl;
  }  
  return 0;
}
