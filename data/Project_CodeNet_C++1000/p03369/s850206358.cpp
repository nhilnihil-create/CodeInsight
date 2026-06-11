#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s; cin >> s;
  int ans = 700;
  if (s[0] == 'o') ans += 100;
  if (s[1] == 'o') ans += 100;
  if (s[2] == 'o') ans += 100;
  cout << ans << endl;
  return 0;
}