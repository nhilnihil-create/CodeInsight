#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> V(N);
  rep(i, N) cin >> V[i];
  int pic = min(N, K);
  ll ans = 0;
  for (int i = 0; i <= pic; i++) {
    for (int j = 0; j <= pic - i; j++) {
      vector<ll> A(0);
      vector<ll> B(0);
      for (int k = 0; k < i; k++) {
        if (V[k] >= 0) A.push_back(V[k]);
        else B.push_back(V[k]);
      }
      for (int k = 0; k < j; k++) {
        if (V[N-1-k] >= 0) A.push_back(V[N-1-k]);
        else B.push_back(V[N-1-k]);
      }
      sort(B.begin(), B.end());
      reverse(B.begin(), B.end());
      int pop = K - i - j;
      while (pop > 0) {
        if (!B.empty()) {
          B.pop_back();
        }
        pop--;
      }
      ll sum = 0;
      for (auto a : A) sum += a;
      for (auto b : B) sum += b;
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}