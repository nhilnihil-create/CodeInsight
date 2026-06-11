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
  vector<int> a(n), b(n);
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    sum -= b[i];
  }
  if(sum < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> d;
  int limit = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] > b[i]) {
      d.push_back(a[i] - b[i]);
      limit++;
    }
  }
  sort(d.rbegin(), d.rend());
  int cnt = 0;
  int ans = 0;

  for(int i = 0; i < n; i++) {
    if(a[i] < b[i]) {
      ans++;
      while(a[i] < b[i]) {
        if(abs(a[i] - b[i]) >= d[cnt]) {
          a[i] += d[cnt];
          d[cnt] = 0;
          cnt++;
          if(cnt == limit) {
            break;
          }
        } else {
          d[cnt] -= (b[i] - a[i]);
          a[i] = b[i];
        }
      }
    }
  }
  if(ans > 0) {
    cnt++;
  }
  cout << cnt + ans << endl;
  return 0;
}