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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> vec;
  char bef = s[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (bef != s[i]) {
      vec.push_back(bef == '0' ? -cnt : cnt);
      cnt = 1;
    } else {
      cnt++;
    }
    bef = s[i];
  }
  vec.push_back(bef == '0' ? -cnt : cnt);
  n = vec.size();
  int ans = 0, sum = 0;
  int j = 0;
  cnt = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n) {
      if (0 <= vec[j]) {
        sum += vec[j];
        j++;
      } else {
        if (cnt < k) {
          sum -= vec[j];
          j++;
          cnt++;
        } else {
          break;
        }
      }
    }
    ans = max(ans, sum);
    if (i == j) {
      j++;
    } else {
      if (vec[i] < 0) {
        sum += vec[i];
        cnt--;
      } else {
        sum -= vec[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}