#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int X, Y;

int main(int argc, char* argv[]) {
  cin >> X >> Y;

  int res = 1;
  while (Y / 2 >= X) {
    Y /= 2;
    res++;
  }
  cout << res << endl;

  return 0;
}