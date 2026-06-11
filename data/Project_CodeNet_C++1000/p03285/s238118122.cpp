#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= 25; ++i) {
    for (int j = 0; j <= 14; ++j) {
      if (i * 4 + j * 7 == n) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}