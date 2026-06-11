#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int count = 0;

  if (A == B && B == C) { // do nothing
  } else {
    int mx = std::max(std::max(A, B), C);
    count += (mx - A) / 2;
    A += (mx - A) / 2 * 2;
    count += (mx - B) / 2;
    B += (mx - B) / 2 * 2;
    count += (mx - C) / 2;
    C += (mx - C) / 2 * 2;

    if (A == B && B == C) { // do nothing
    } else if (A == B || B == C || C == A) {
      if (A + B + C == 3 * mx - 1) count += 2;
      else count++;
    } else {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
