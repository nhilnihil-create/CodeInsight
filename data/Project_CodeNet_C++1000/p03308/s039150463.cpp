#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;

int main() {
  ll N,Max;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  Max = 0;
  rep(i, N) {
    for(ll j = i;j < N;j++) {
      Max = max(Max, abs(A[i] - A[j]));
    }
  }
  cout << Max << endl;
  return 0;
}
