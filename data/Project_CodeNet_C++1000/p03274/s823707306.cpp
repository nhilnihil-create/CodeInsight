#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  long long n, k, ans = 1000000000, dis;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n-k+1; i++) {
    // cout << x[i] << ' ' << x[i+k-1] << endl;
    if (x[i]<0) {
      if (x[i+k-1]<0) {
        dis = -1*x[i];
      } else {
        dis = -1*x[i] + x[i+k-1] + min(-1*x[i],x[i+k-1]);
      }
    } else {
      dis = x[i+k-1];
    }
    ans = min(dis, ans);
  }
  cout << ans << endl;
}