#include <cmath>
#include <ios>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int d, n;
  cin >> d >> n;

  if (n == 100) {
    cout << static_cast<int>(pow(100, d)) * (n + 1) << '\n';
  } else {
    cout << static_cast<int>(pow(100, d)) * n << '\n';
  }
  return 0;
}