#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  int64_t K;
  cin >> S >> K;
  char result = '1';
  for (int64_t i = 0; i < K; ++i) {
    if (S[i] != '1') {
      result = S[i];
      break;
    }
  }
  cout << result << endl;
  return 0;
}
