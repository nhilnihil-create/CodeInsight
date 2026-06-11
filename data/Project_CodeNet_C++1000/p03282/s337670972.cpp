#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int ichinum = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '1')
      ++ichinum;
    else
      break;
  }
  if (ichinum >= K)
    cout << 1 << endl;
  else
    cout << S[ichinum] << endl;
}