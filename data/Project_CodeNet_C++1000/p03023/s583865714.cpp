#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

bool in(int target, int max) { return 0 <= target && target < max - 1; }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  cout << 180 * N - 360 << endl;
  return 0;
}
