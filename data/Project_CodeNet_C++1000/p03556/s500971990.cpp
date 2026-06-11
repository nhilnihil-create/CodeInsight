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
  ll N;
  cin >> N;
  ll max_v = 1;
  for (int i = 1; i * i <= N; i++) {
    max_v = i * i;
  }
  cout << max_v << endl;
  return 0;
}