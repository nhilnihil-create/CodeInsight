#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;

  int diff = 999;
  for (size_t i = 0; i < S.size()-2; ++i) {
    int n = stoi(S.substr(i, 3));
    diff = min(diff, abs(753 - n));
  }
  cout << diff << endl;
  
  return 0;
}
