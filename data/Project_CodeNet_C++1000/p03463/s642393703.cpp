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
  ll N, A, B;
  cin >> N >> A >> B;
  if ((B - A) % 2 == 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }
  return 0;
}