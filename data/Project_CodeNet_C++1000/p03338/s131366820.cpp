#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string S;
  cin >> S;

  int answer = 0;
  for (int i = 1; i < N; ++i) {
    vector<bool> kind(26, false);
    for (int j = 0; j < i; ++j) {
      kind[S[j] - 'a'] = true;
    }
    int count = 0;
    for (int j = i; j < N; ++j) {
      if (kind[S[j] - 'a']) {
        count++;
        kind[S[j] - 'a'] = false;
      }
    }
    answer = max(answer, count);
  }
  cout << answer << endl;
  return 0;
}
