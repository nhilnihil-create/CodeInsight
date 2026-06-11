#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll N,M; cin>>N>>M;
  if(N>=M) {cout<<0<<endl; return 0;}
  vector<ll> X(M);
  rep(i,M)
  {
    cin>>X.at(i);
  }
  sort(X.begin(),X.end());
  ll all=0;
  vector<ll> sa(M-1);
  rep(i,M-1)
  {
    sa.at(i)=X.at(i+1)-X.at(i);
    all+=sa.at(i);
  }
  sort(sa.rbegin(),sa.rend());
  rep(i,N-1)
  {
    all-=sa.at(i);
  }
  cout<<all<<endl;
  return 0;
}
