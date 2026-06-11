#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int K; cin >> K;
  int even = K / 2;
  int odd = (K + 1) / 2;
  cout << even * odd << endl;
}
