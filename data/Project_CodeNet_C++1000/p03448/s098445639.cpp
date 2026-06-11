#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll a,b,c,x;
  cin >> a >> b >> c >> x;
  ll ans = 0;
  
  rep(i,a+1){
    rep(j,b+1){
      rep(k,c+1){
        if(500*i + 100*j + 50*k == x)
          ans++;
      }
    }
  }
  cout << ans << endl;
}
