#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

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

int main() {
  ll n,x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  if(n==1){
    cout << abs(x-a.at(0)) << endl;
    return 0;
  }
  else{
    ll ans=abs(x-a.at(0));
    for(int i=0;i<n-1;i++){
      ans=gcd(ans,abs(a.at(i+1)-a.at(i)));
    }
    cout << ans << endl;
  }
}