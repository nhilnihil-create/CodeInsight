#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int N = S.size();
  bool ok = true;
  bool cflag = false;
  rep(i, N) {
    if (i == 0) {
      if (S[i] != 'A') ok = false;
    } else if (!cflag && 2 <= i && i <= N - 2 && S[i] == 'C') {
      cflag = true;
    } else {
      if ('A' <= S[i] && S[i] <= 'Z') ok = false;
    }
  }
  if (!cflag) ok = false;
  cout << (ok ? "AC" : "WA") << endl;
  return 0;
}