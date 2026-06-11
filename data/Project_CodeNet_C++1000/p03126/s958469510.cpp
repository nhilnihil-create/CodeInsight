#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  int N,M;
  cin >> N >> M;

  vector<int> votes(M,0);

  int K,A;
  for (auto i = 0; i != N; ++i) {
    cin >> K;
    for (auto j = 0; j != K; ++j) {
      cin >> A;
      ++votes[A-1];
    }
  }

  int ans{};
  for (auto i = 0; i != M; ++i) {
    if (votes[i]==N) {
      ++ans;
    }
  }

  cout << ans << endl;
  
  return 0;
}
