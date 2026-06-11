#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  int N, M;
  cin >> N >> M;

  long double ret = 0;

  // all passed
  ret = (M * 1900 + (N - M) * 100) * pow(2, M);

  cout << ret << endl;
  return 0;
}