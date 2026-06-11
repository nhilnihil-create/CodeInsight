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
  ll cnt = 0;
  ll k = N / 2 + N % 2;
  string ans = "YES";
  if (k < K) ans = "NO";
  cout << ans << endl;
  return 0;
}