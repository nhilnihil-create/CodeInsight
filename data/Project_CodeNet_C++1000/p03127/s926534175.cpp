#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  int a; cin >> a;
  int ans = a;
  rep(i,n-1){
    int b; cin >> b;
    if(ans > __gcd(a,b)) ans = __gcd(a,b);
  }
  
  cout << ans << endl;
}