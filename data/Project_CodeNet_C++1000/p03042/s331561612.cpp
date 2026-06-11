#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  string s;
  cin >> s;
  bool mm1 = false, mm2 = false;
  if ("01" <= s.substr(0, 2) && s.substr(0, 2) <= "12") {
    mm1 = true;
  }
  if ("01" <= s.substr(2, 2) && s.substr(2, 2) <= "12") {
    mm2 = true;
  }
  string ans = "";
  if (mm1 && mm2) {
    ans = "AMBIGUOUS";
  } else if (mm1) {
    ans = "MMYY";
  } else if (mm2) {
    ans = "YYMM";
  } else {
    ans = "NA";
  }
  cout << ans << endl;
  return 0;
}