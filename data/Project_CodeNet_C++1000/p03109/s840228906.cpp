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
  string s;
  cin >> s;
  int m = stoi(s.substr(5, 2));
  int d = stoi(s.substr(8, 2));
  cout << (m <= 4 && d <= 30 ? "Heisei" : "TBD") << endl;
  return 0;
}
