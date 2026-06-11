#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int N = S.size();

  vector<bool> dict(26, true);
  for (int i = 0; i < N; ++i) {
    dict[S[i] - 'a'] = false;
  }
  for (int i = 0; i < 26; ++i) {
    if (dict[i]) {
      cout << S << char(i + 'a') << endl;
      return 0;
    }
  }

  dict[S[N - 1] - 'a'] = true;
  for (int i = N - 2; i >= 0; --i) {
    for (char next = S[i] + 1; next <= 'z'; ++next) {
      if (next <= 'z' && dict[next - 'a']) {
        S[i] = next;
        cout << S.substr(0, i + 1) << endl;
        return 0;
      }
    }
    dict[S[i] - 'a'] = true;
  }
  cout << -1 << endl;
  return 0;
}