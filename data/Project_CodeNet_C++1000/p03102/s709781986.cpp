#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n,m,c; cin >> n >> m >> c;
  vector<int> B(m);
  rep(i,m)  cin >> B[i];
  int ans = 0;
  
  rep(i,n){
    int sum = c;
    rep(j,m){
      int a; cin >> a;
      sum += a*B[j];
    }
    if(sum > 0) ans++;
  }
  
  cout << ans << endl;
}