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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') r++;
  }
  cout << (r > n - r ? "Yes" : "No") << endl;
  return 0;
}