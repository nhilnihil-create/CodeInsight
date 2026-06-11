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
  ll win = 0;
  int k = S.length();
  for (int i = 0; i < k; i++) {
    if (S[i] == 'o') {
      win++;
    }
  }
  string ans = ((15 - k) + win >= 8) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}