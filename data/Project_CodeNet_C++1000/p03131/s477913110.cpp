#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll K,A,B; cin>>K>>A>>B;
  if(B-A<=2) {cout<<K+1<<endl; return 0;}
  K-=(A-1);
  ll ans=A;
  ans+=(B-A)*(K/2)+K%2;
  cout<<ans<<endl;
  return 0;
}
