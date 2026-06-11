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
  vector<ll> a(n), b(n);
  ll sumA = 0, sumB = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sumA += a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    sumB += b[i];
  }

  ll c = sumB - sumA;
  for(int i = 0; i < n; i++) {
    if(a[i] < b[i]) {
      // b[n - 1] += (b[i] - a[i] + 1) / 2;
      c -= (b[i] - a[i] + 1) / 2;
    } else if(a[i] == b[i]) {
      continue;
    } else {
      // a[i + 1] += (a[i] - b[i]) * 2;
      // c -= a[i] - b[i];
    }
  }
  if(c >= 0) {
    cout << "Yes\n";
  } else {

    cout << "No\n";
  }
  return 0;
}