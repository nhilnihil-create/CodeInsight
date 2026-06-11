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
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  rep(i, n) {
    int x;
    cin >> x;
    mp[x]++;
  }
  vector<int> v;
  for (auto el : mp) v.push_back(el.second);
  sort(v.begin(), v.end(), less<int>());
  int ans = 0;
  int num = mp.size() - k;
  rep(i, num) ans += v[i];
  cout << ans << endl;
  return 0;
}
