#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  for (int i = 0; 4 * i <= N; ++i) {
    if ((N - 4*i) % 7 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
