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

int main() {
  ll K;
  cin >> K;
  ll ans = 0;
  for (int i = 1; i <= K; i++) {
    for (int j = i + 1; j <= K; j++) {
      if (i % 2 != j % 2) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}