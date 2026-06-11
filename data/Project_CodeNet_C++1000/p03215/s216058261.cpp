#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n)cin >> a[i];
  vector<ll> s(n+1,0);
  rep(i,n)s[i+1] = s[i]+a[i];
  vector<ll> v;
  rep(i,n)for(int j = i;j < n;j++)v.push_back(s[j+1]-s[i]);
  ll res = 0;
  for(ll i = 60;i >= 0;i--){
    vector<ll> u;
    rep(j,v.size())if(v[j] >> i & 1)u.push_back(v[j]);
    if(u.size() >= k){
      res += (1ll << i);
      v = u;
    }
  }
  cout << res << endl;






  return 0;
}