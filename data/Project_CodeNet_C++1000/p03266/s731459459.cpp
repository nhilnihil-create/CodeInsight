#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int n,k;
  cin >> n >> k;
  ll res = 0;
  res += 1LL*(n/k)*(n/k)*(n/k);
  if(!(k & 1))res += 1LL*((n+k/2)/k)*((n+k/2)/k)*((n+k/2)/k);
  cout << res << endl;





  return 0;
}
