#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 10010005;

struct open {
  int w, s, v;
  open(int w, int s, int v) : w(w), s(s), v(v) {}
}; vector <open> vec;

inline bool cmp(const open &a, const open &b) {
  return (a.w + a.s < b.w + b.s);
}

int n;
long long dp[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    vec.push_back(open(x, y, z));
  }
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < vec.size(); i++) {
    for (int j = vec[i].s; j >= 0; j--) {
      dp[j + vec[i].w] = max(dp[j + vec[i].w], dp[j] + vec[i].v);
    }
  }
  cout << *max_element(dp, dp + N) << endl;
  return 0;
}
