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
  string s; cin >> s;
  for (auto i : s) {
    if (i == '1') cout << '9';
    if (i == '9') cout << '1';
  }
  cout << endl;
  return 0;
}