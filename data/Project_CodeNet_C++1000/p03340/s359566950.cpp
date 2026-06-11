#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

inline bool isOK(vector<int>& sum) {
  rep(i, 20) {
    if (sum[i] >= 2) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  int right = 0;
  int sum = 0;
  int64_t answer = 0;
  rep(left, N) {
    while (right < N && (sum ^ A[right]) == (sum + A[right])) {
      sum += A[right];
      ++right;
    }
    answer += (int64_t)(right - left);
    sum -= A[left];
  }
  cout << answer << endl;
  return 0;
}