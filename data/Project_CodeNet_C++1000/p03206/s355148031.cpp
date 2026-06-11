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
  ll D;
  cin >> D;
  if (D == 25) {
    cout << "Christmas" << endl;
  } else if (D == 24) {
    cout << "Christmas Eve" << endl;
  } else if (D == 23) {
    cout << "Christmas Eve Eve" << endl;
  } else {
    cout << "Christmas Eve Eve Eve" << endl;
  }
  return 0;
}