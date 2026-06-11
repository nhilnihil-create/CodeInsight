#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }

  if (b <= 8) {
    cout << "Yay!" << '\n';
  } else {
    cout << ":(" << '\n';
  }
  return 0;
}