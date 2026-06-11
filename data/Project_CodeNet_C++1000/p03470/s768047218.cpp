#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main(){
  int n; cin >> n;
  vector<ll> v(n); rep(i,n) cin >> v.at(i);
  
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v.size() << endl;;
}
