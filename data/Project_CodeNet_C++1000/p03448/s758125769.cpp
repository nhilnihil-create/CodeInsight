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
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int count = 0;
  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {
        if (500 * a + 100 * b + 50 * c == X) count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
