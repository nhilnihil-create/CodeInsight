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
  ll A, B, C;
  cin >> A >> B >> C;
  if (A == B) {
    cout << C << endl;
  } else if (A == C) {
    cout << B << endl;
  } else {
    cout << A << endl;
  }
  return 0;
}