#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
string S;
int N;

bool isOK(int K) {
  bool ok = true;
  for (int i = N - K; i < K - 1; ++i) {
    if (S[i] != S[i + 1]) {
      ok = false;
      break;
    }
  }
  return ok;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> S;
  N = S.size();
  int left = 1;
  int right = N + 1;
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (isOK(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}