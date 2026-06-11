#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll r,d,x; cin >> r >> d >> x;
  ll g = x;
  
  rep(i, 10){
    g = r*g - d;
    cout << g << endl;
  }
}