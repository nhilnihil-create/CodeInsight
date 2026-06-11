#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n,m;
  cin >> n >> m;
  
  vector<pair<ll ,ll>> v(n);
  rep(i,n) cin >> v.at(i).first >> v.at(i).second;
  
  sort(v.begin(),v.end());
  
  ll ans = 0;
  rep(i,n)
  {
    if(m - v.at(i).second > 0)
    {
      ans += v.at(i).first * v.at(i).second;
      m -= v.at(i).second;
    }else{
      ans += v.at(i).first * m;
      break;
    }
  }
  
  cout << ans << endl;
  
 
}