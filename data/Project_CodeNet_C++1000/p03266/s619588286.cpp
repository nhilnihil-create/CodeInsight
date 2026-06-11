#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N, K; cin >> N >> K;
  ll x = N/K;
  if (K%2 == 0) {
    ll y = N/(K/2)-N/K;
    cout << x*x*x+y*y*y << endl;
  } else {
    cout << x*x*x << endl;
  }
}