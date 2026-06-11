#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) { cin >> A[i]; }

  vector<int64_t> SUM(N + 1);
  SUM[0] = 0;
  rep(i, N) {
    SUM[i + 1] = SUM[i] + A[i];
    // cout << SUM[i+1] << " ";
  }
  // cout << endl;

  unordered_map<int64_t, int64_t> hist;
  int64_t answer = 0;
  rep(i, N) {
    answer += (int64_t)hist[SUM[i + 1]];
    hist[SUM[i + 1]]++;
  }
  answer += hist[0];
  cout << answer << endl;
  return 0;
}