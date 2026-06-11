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
  ll ans;
  rep(i,N)
  {
    if(i==0) {cin>>ans;}
    ll A; cin>>A;
    ans=gcd(A,ans);
  }
  cout<<ans<<endl;  
  return 0;
}
