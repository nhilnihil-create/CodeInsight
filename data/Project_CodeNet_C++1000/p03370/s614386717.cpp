#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)

void solve(ll N, ll X, vector<ll> m) {
  ll s = accumulate(ALL(m),0);
  ll mi = *min_element(ALL(m));
  cout << N+(X-s)/mi << endl;
}

int main() {
  ll N;
  cin >> N;
  ll X;
  cin >> X;
  vector<ll> m(N);
  for (int i = 0; i < N; i++) {
    cin >> m[i];
  }
  solve(N, X, move(m));
  return 0;
}
