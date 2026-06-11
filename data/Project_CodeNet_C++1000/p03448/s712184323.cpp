#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int count = 0;
  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      int rest = X - 500 * i - 100 * j;
      if (rest >= 0 && rest % 50 == 0 && rest / 50 <= C) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
