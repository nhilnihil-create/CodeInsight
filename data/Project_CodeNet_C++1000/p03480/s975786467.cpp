#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N;
  N = S.size();

  int left = 0;
  int right = N - 1;
  int tmp_ans0 = 0;
  int tmp_ans1 = N;
  while (left < right) {
    if (S[left] != S[left + 1]) tmp_ans0 = left + 1;
    if (S[right - 1] != S[right]) tmp_ans1 = right;
    left++, right--;
  }
  int answer = min(N - tmp_ans0, tmp_ans1);
  cout << answer << endl;
  return 0;
}