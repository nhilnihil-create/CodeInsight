#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (auto &v : {111, 222, 333, 444, 555, 666, 777, 888, 999, 1111})
    if (n <= v) {
      cout << v << endl;
      break;
    }
}