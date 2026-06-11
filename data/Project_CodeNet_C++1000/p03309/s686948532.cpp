#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
vector<ll> a;

ll sad(ll x) {
  ll n = 0;
  for (ll i = 0; i < N; i++) {
    n+= abs(x-a[i]);
  }
  return n;
}


int main() {
  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x; x -= (i+1); a.push_back(x);
  }
  sort(a.begin(), a.end());
  cout << sad(a[(N+1)/2-1]) << endl;
}