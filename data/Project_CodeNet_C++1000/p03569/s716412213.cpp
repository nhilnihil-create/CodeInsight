#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;

  int left = 0;
  int right = S.size() - 1;
  int answer = 0;
  while (left <= right) {
    if (S[left] == S[right]) {
      left++;
      right--;
    } else {
      if (S[left] == 'x') {
        answer++;
        left++;
      } else if (S[right] == 'x') {
        answer++;
        right--;
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
