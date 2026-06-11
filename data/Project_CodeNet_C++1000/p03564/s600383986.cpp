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
  ll N, K;
  cin >> N >> K;
  ll cur = 1;
  for (int i = 0; i < N; i++) {
    cur = min(cur * 2, cur + K);
  }
  cout << cur << endl;
  return 0;
}