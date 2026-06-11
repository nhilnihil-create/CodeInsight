#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1001001001;

int main() {
  int a, b;
  cin >> a >> b;

  cout << (b % a == 0 ? a + b : b - a);
  return 0;
}
