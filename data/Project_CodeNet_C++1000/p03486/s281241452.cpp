#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  if (s < t) {
    cout << "Yes" << endl;
  } else cout << "No" << endl;
  return 0;
}