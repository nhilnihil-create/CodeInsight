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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int tmp = 0;
    for(int j = 0; j < m; j++) {
      int a;
      cin >> a;
      tmp += a * b[j];
    }
    tmp += c;
    if(tmp > 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}