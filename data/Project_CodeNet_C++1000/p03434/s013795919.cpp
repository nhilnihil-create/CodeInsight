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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int asum = 0, bsum = 0;
  for (int i = 0; i < n; ++i) {
    if ((i & 1) == 0)
      asum += a[i];
    else
      bsum += a[i];
  }
  cout << asum - bsum << endl;
  return 0;
}