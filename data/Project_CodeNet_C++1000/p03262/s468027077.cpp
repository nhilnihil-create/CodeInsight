#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a / gcd(a, b)*b;
}




int main() 
{
  ll N; cin>>N;
  vector<ll> x(N+1);
  rep(i,N+1)
  {
    cin>>x.at(i);
  }
  sort(x.begin(),x.end());
  vector<ll> sa(N);
  rep(i,N)
  {
    sa.at(i)=x.at(i+1)-x.at(i);
  }
  ll ans;
  rep(i,N)
  {
    if(i==0) {ans=sa.at(0); continue;}
    ans=gcd(ans,sa.at(i));
  }
  cout<<ans<<endl;
  return 0;
}