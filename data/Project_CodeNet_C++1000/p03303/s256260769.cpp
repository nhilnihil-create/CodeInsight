#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  int w;
  cin >> w;
  for (auto i = 0; i < S.size(); i+=w) {
    cout << S[i];
  }
  cout << endl;
  return 0;
}
