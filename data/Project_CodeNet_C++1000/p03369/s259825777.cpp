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
  string S;
  cin >> S;
  ll ans = 700;
  if (S[0] == 'o') ans += 100;
  if (S[1] == 'o') ans += 100;
  if (S[2] == 'o') ans += 100;
  cout << ans << endl;
  return 0;
}