#include <iostream>

using namespace std;

int main() {
  string S;
  long long K;
  cin >> S >> K;
  char ans{'1'};
  for (int i = 0; i != K; ++i) {
    if (S[i] != ans) {
      ans = S[i];
      break;
    }
  }
  cout << ans << endl;
}
