#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,m;
  cin >> n >> m;
  vector<vector<ll>> v(n,vector<ll>(3));
  rep(i,n)rep(j,3)cin >> v[i][j];
  int c[] = {-1,1};
  ll res = 0;
  for(int bit = 0;bit < 8;bit++){
    vector<ll> k(n,0);
    rep(j,3)rep(i,n)k[i] += v[i][j]*c[bit >> j & 1];
    sort(ALL(k),greater<ll>());
    ll sum = 0;
    rep(i,m)sum += k[i];
    res = max(res,sum);
  }
  cout << res << endl;
  
  



  return 0;
}