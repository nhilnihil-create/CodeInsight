#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  for (int i = 1; i <= 9; ++i) {
    int v = i*100 + i*10 + i;
    if (v >= N) {
      cout << v << endl;
      return 0;
    }
  }
}
