#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n,y;
  cin >> n >> y;
  
  rep(i, n+1){
    rep(j, n-i+1){
      if(10000*i + 5000*j + 1000*(n-i-j) == y){
        cout << i << " " << j << " " << n-i-j << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}
