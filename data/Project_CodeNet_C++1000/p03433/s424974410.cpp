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
  ll N, A;
  cin >> N >> A;
  N = N - 500 * (N / 500);
  if (N <= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}