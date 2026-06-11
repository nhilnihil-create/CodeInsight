#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool black = false;
  vector<int> sum(n + 1, 0);
  for(int i = 0; i < n; i++) {
    if(s[i] == '#') {
      sum[i + 1] = sum[i] + 1;
      black = true;
    } else {
      sum[i + 1] = sum[i];
    }
  }
  int mini = 1001001001;
  for(int i = 0; i <= n; i++) {
    int pre = sum[i];
    mini = min(mini, n - i - (sum[n] - pre) + pre);
  }
  cout << mini << endl;

  return 0;
}