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
  vector<ll> x(n), y(n), h(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      int idx = 0;
      while(h[idx] == 0) {
        idx++;
      }
      ll tmpH = abs(i - x[idx]) + abs(j - y[idx]) + h[idx];
      bool ok = true;
      for(int k = 0; k < n; k++) {
        if(h[k] == max(tmpH - abs(i - x[k]) - abs(j - y[k]), (ll)0)) {
          continue;
        } else {
          ok = false;
          break;
        }
      }
      if(ok) {
        cout << i << " " << j << " " << tmpH << '\n';
        return 0;
      }
    }
  }
  return 0;
}