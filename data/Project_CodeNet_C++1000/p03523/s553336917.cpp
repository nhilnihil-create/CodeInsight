#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;

  for (int i = 0; i < 1 << 4; ++i) {
    string T;
    for (int j = 0; j < 4; ++j) {
      if (i & 1 << j)
        T += 'A';
      if (j == 0)
        T += "KIH";
      if (j == 1)
        T += 'B';
      if (j == 2)
        T += 'R';
    }

    if (S == T) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}