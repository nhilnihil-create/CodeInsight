#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i <= (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll R,G,B,N; cin>>R>>G>>B>>N;
  ll count=0;
  rep(r,N/R)
  {
    rep(g,N/G)
    {
      if(R*r+G*g<=N&&(N-R*r-G*g)%B==0) 
      {
        //cout<<r<<" "<<g<<" "<<N-r-g<<endl;
        count++;
      }
    }
  }
  cout<<count<<endl;
  return 0;
}
