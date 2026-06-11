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
  ll A, B, X;
  cin >> A >> B >> X;
  if (X < A) {
    cout << "NO" << endl;
  } else if (A == X) {
    cout << "YES" << endl;
  } else if (A + B < X) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}