#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N; cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (i%2==0) continue;
    int temp = 0;
    for (int j = 1; j <= i; ++j) {
      if (i%j==0) ++temp;
    }
    if (temp==8) ++ans;
  }
  cout << ans << endl;
  return 0;
}