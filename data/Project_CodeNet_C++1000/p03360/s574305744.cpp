#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

bool b[1010];

void solve(){

    ll a,b,c;
    cin >> a >> b >> c;
    ll k;
    cin >> k;
    ll ma = max(a,max(b,c));
    ll t = ll(pow(2,k));
    cout << a+b+c+t*ma-ma << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
