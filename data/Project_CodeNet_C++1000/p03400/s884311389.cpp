#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int D, X; cin >> D >> X;
  for (int i = 0; i < N; ++i) {
    int A; cin >> A;
    int d = 1;
    while (d <= D) {
      ++X; d += A;
    }
  }
  cout << X << endl;
}
