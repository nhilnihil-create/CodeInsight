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
  ll A, B, K;
  cin >> A >> B >> K;
  set<ll> ans;
  for (int i = A; i < A + K && i <= B; i++) {
    ans.insert(i);
  }
  for (int i = B; i > B - K && i >= A; i--) {
    ans.insert(i);
  }
  for (auto x : ans) {
    cout << x << endl;
  }
  return 0;
}