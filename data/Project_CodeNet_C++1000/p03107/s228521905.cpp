#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  vector<int> cnt(2, 0);

  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - '0']++;
  }
  cout << min(cnt[0], cnt[1]) * 2 << endl;
  return 0;
}