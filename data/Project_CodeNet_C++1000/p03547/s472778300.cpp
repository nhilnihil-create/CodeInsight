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
  char x, y;
  cin >> x >> y;
  if (x > y) {
    cout << ">" << endl;
  } else if (x < y) {
    cout << "<" << endl;
  } else {
    cout << "=" << endl;
  }
  return 0;
}