#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

// 約数の列挙O(√n)
int divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res.size();
}

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 1 && divisor(i) == 8) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}