#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S; cin >> S;
  int zero = 0, one = 0;
  for (auto i : S) {
    if (i == '0') ++zero;
    else ++one;
  }
  cout << 2 * min(zero, one) << endl;
}