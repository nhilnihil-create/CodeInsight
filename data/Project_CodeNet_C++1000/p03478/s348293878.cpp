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
  ll N, A, B;
  cin >> N >> A >> B;
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    string str = to_string(i);
    ll sum = 0;
    for (int i = 0; i < str.size(); i++) {
      sum += (str[i] - '0');
    }
    if (A <= sum && sum <= B) ans += i;
  }
  cout << ans << endl;
  return 0;
}