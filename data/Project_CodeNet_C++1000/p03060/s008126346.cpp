#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, vector<ll> V, vector<ll> C) {
  int ans{};
  for (auto i=0; i!=N; ++i) {
    if(V[i]>C[i]) {
      ans += V[i] - C[i];
    }
  }
  cout << ans << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> V(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  vector<ll> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  solve(N, move(V), move(C));
  return 0;
}
