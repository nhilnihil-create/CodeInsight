#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  vector<int> p(n),q(n);
  rep(i,n)  cin >> p[i];
  rep(i,n)  cin >> q[i];
  int ans = 0;
  
  rep(i,n){
    if(p[i] > q[i])  
      ans += p[i] - q[i];
  }
  
  cout << ans << endl;
}