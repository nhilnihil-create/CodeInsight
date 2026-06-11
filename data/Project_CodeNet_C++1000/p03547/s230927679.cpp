#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  char a, b;
  cin >> a >> b;
  if (a == b)
    cout << "=";
  else if (a > b)
    cout << ">";
  else
    cout << "<";
  cout << endl;
  return 0;
}