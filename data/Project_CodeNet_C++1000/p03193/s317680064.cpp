#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(ll i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  ll n,h,w;
  cin >> n >> h >> w;
  vector<ll> A(n+10);
  vector<ll> B(n+10);
  ll ans = 0;
  rep(i,n){
    cin >> A[i] >> B[i];
    if(A[i] >= h && B[i] >= w) ++ans;
  }
  cout << ans << endl;
  return 0;
}
