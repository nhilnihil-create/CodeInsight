#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  scanf("%d", &n);
  for (m = 1; ; ++m) {
    if (m * (m - 1) / 2 >= n) break;
  }
  if (m * (m - 1) / 2 != n) {
    puts("No");
    return 0;
  }
  puts("Yes");
  printf("%d\n", m);
  vector<vector<int>> ret(m, vector<int>());
  int k = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      ret[i].push_back(k);
      ret[j].push_back(k);
      ++k;
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d", (int)ret[i].size());
    for (int j = 0; j < ret[i].size(); ++j) {
      printf(" %d", ret[i][j]);
    }
    puts("");
  }
  return 0;
}
