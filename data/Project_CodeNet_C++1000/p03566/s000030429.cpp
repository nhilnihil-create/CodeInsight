#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> v(n + 2, 0), t(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    t[i] += t[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<double> maxv(2*t[n]+1);
  int ti = 1;
  for (int i = 1; i <= n; i++) {
    while(ti < 2*t[i]) {
      maxv[ti] = v[i];
      ti++;
    }
    maxv[ti] = min(v[i], v[i + 1]);
    ti++;
  }
  
  for (int i = 1; i < 2*t[n]; i++) {
    maxv[i] = min(maxv[i], maxv[i-1] + 0.5);
  }
  for(int i=2*t[n]-1; i>=0; i--){
    maxv[i] = min(maxv[i], maxv[i+1]+0.5);
  }

  double ans = 0;
  for (int i = 0; i < 2*t[n]; i++) {
    ans += 0.5 / 2 *(maxv[i]+maxv[i+1]);
  }
  cout << fixed << ans << endl;
  return 0;
}
