#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n,z,w;
  cin >> n >> z >> w;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  ll res = abs(v.back()-w);
  for(int i = n-2;i >= 0;i--){
    ll res_ = 1e18;
    for(int j = i+1;j < n;j++){
      if(j != n-1)res_ = min(res_,abs(v[j]-v.back()));
      else res_ = min(res_,abs(v[i]-v[j]));
    }
    res = max(res,res_);
  }
  cout << res << endl;


  return 0;
}