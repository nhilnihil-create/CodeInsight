#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N,K; cin>>N>>K;
  if(K==2) {cout<<N-1<<endl; return 0;}
  ll ans=N/(K-1);
  if(N%(K-1)>1) {ans++;}
  cout<<ans<<endl;
  return 0;
}