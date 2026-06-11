#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(ll x, ll y, ll X, ll Y) {
  if (y < X+1) return false;
  if (Y < x+1) return false;
  return true;
}

int main() {
  ll N, M, X, Y; cin >> N >> M >> X >> Y;
  ll Ma = -1000;
  ll mb = 1000;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a; Ma = max(Ma, a);
  }
  for (ll i = 0; i < M; i++) {
    ll b; cin >> b; mb = min(mb, b);
  }
  
  if (Ma < mb && ok(Ma,mb,X,Y)) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}
  