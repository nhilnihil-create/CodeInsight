#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<ll, ll> m;
  m[0]++;
  ll s = 0;
  for (int i = 0; i < n; i++){
    s += a[i];
    m[s]++;
  }


  ll ans = 0;
  for (auto p : m){
    ll v = p.second;
    ans += v * (v - 1)/2;
  }
  cout << ans << endl;

  return 0;
}
