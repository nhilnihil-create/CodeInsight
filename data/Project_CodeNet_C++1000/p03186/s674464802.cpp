#include <iostream>
using namespace std;

int main(void) {
  int64_t A, B, C;
  cin >> A >> B >> C;
  int64_t answer = 0;
  if ((A + B) < C) {
    answer = (A + B + 1) + B;
  } else {
    answer = B + C;
  }
  cout << answer << endl;
  return 0;
}