#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < 10; ++i)
    if (n <= i * 111) {
      cout << i * 111 << endl;
      break;
    }
}
