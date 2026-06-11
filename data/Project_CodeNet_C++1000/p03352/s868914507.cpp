#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int X; cin >> X;
  int vmax = 1;
  for (int i = 2; i < X; ++i) {
    int j = i * i;
    while (j <= X) {
      vmax = max(vmax, j);
      j *= i;
    }
  }
  cout << vmax << endl;
}
