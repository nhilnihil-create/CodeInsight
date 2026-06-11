#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int a, b; cin >> a >> b;
  int N = b - a;
  cout << (1 + N) * N / 2 - b << endl;
}
