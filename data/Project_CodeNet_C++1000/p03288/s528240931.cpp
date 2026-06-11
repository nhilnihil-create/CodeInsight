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
  ll R;
  cin >> R;
  if (2800 <= R) {
    cout << "AGC" << endl;
  } else if (1200 <= R && R < 2800) {
    cout << "ARC" << endl;
  } else if (R < 1200) {
    cout << "ABC" << endl;
  }
  return 0;
}