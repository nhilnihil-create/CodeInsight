#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  long double T, X;
  cin >> T >> X;

  printf("%.10Lf\n", T / X);

  return 0;
}
