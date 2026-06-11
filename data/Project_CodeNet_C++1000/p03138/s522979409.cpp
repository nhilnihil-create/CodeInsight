#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, K;
  cin >> N >> K;

  vector<int> Knum(60, 0);
  int j = 0;
  int64_t K0 = K;
  while (K0) {
    if (K0 % 2) Knum[j]++;
    K0 /= 2;
    ++j;
  }

  vector<int64_t> A(N);
  vector<int64_t> Anum(60, 0);
  rep(i, N) {
    int64_t a;
    cin >> a;
    A[i] = a;
    int j = 0;
    while (a) {
      if (a % 2) Anum[j]++;
      a /= 2;
      ++j;
    }
  }

  int64_t answer = 0;
  rep(i, N) { answer += (K ^ A[i]); }
  for (int d = 60; d >= 0; --d) {
    if (Knum[d] == 0) continue;
    int64_t X = 0;
    for (int i = 60; i >= 0; --i) {
      if (d < i) {
        if (Knum[i] == 1) X |= (1LL << i);
      } else if (i < d) {
        if (Anum[i] <= (N - Anum[i])) X |= (1LL << i);
      }  // in case of i == d, forcing set to 0 to make carry.
    }
    int64_t tmp_ans = 0;
    rep(i, N) { tmp_ans += (X ^ A[i]); }
    answer = max(answer, tmp_ans);
  }
  cout << answer << endl;
  return 0;
}
