#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);

ll gcd(ll a,ll b)
{
   if(a%b==0)
   {
       return(b);
   }
   else
   {
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}



int main() 
{
  ll N,M; cin>>N>>M;
  string S,T; cin>>S>>T;
  ll hoge=gcd(N,M);
  rep(i,hoge)
  {
    if(S.at(i*(N/hoge))!=T.at(i*(M/hoge))) {cout<<-1<<endl; return 0;}
  }
  cout<<lcm(N,M)<<endl;
  return 0;
}
