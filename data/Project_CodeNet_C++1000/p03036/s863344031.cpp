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
  int r, d, x;
  cin >> r >> d >> x;
  int ans = x;
  for (int i = 0; i < 10; ++i) {
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}