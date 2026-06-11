#include <iostream>

using namespace std;

const string YES = "Yes";
const string NO = "No";

int main() {
  int N;
  cin >> N;
  bool pred = false;

  for (; N >= 0; N -= 7) {
    if (N % 4 == 0) {
      pred = true;
      break;
    }
  }

  cout << (pred ? YES : NO) << endl;
  return 0;
}
