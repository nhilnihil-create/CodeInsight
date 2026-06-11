#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  cout << min(b + c, a + 2 * b + 1) << endl;
  return 0;
}
