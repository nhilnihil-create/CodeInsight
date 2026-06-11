#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  rep(i, n) cin >> x[i] >> u[i];
  double sum = 0.0;
  rep(i, n) {
    sum += (u[i] == "JPY" ? x[i] : x[i] * 380000);
  }
  printf("%.6f\n", sum);
  return 0;
}
