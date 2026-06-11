#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long long A, B, C, K;
  cin >> A >> B >> C >> K;

  if (K % 2 == 0)
    cout << A - B << endl;
  else
    cout << B - A << endl;

  return 0;
}