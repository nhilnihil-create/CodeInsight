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
  double ans = 0.0;
  for (int i = 1; i <= n; ++i) {
    ll val = i;
    ll pw = 1;
    while (val < k) {
      val *= 2;
      pw *= 2;
    }
    ans += (1.0 / pw);
  }
  printf("%.10f\n", ans / n);
  return 0;
}