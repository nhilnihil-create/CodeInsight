#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  cout << max({A + B, A - B,  A * B}) << endl;
}
