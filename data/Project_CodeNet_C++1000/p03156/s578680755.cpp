#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
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
#include <random>
#include <ctime>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(N);
  rep(i, N) cin>> P[i];

  sort(P.begin(), P.end());

  auto itA = lower_bound(all(P), A + 1);
  auto itB = lower_bound(all(P), B + 1);
  int LCount = distance(P.begin(), itA);
  int MCount = distance(itA, itB);
  int HCount = distance(itB, P.end());

  cout << min(LCount, min(MCount, HCount)) << endl;

  return 0;
}