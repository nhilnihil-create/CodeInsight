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
  ll ans = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '+')
      ans++;
    else
      ans--;
  }
  cout << ans << endl;
  return 0;
}