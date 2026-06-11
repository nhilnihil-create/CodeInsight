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
  ll A, B;
  cin >> A >> B;
  ll ans = 0;
  for (int i = A; i <= B; i++) {
    string str = to_string(i);
    bool flag = true;
    for (int j = 0; j < str.size() / 2; j++) {
      if (str[j] != str[str.size() - 1 - j]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}