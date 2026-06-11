#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  rep(0, s.size()) {
    if (s[i] == '+') {
      ans++;
    } else {
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
