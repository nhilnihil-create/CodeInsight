#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  string S; cin>>S;
  ll N=S.size();
  ll count=0;
  ll num=0;
  rep(i,N)
  {
    if(S.at(i)=='W')
    {
      count++;
      num+=i;
    }
  }
  //cout<<num<<" "<<count<<endl;
  ll ans=num-(ll)(count*(count-1)/2);
  cout<<ans<<endl;
  return 0;
}
