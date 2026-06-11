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
  if(n >= 2)cout  << max(abs(v.back()-w),abs(v.back()-v[n-2])) << endl;
  else cout << abs(v.back()-w) << endl;

  return 0;
}