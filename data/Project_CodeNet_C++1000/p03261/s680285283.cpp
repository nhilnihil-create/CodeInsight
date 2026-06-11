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
  vector<string> w(N);
  set<string> exists;
  cin >> w[0];
  bool succ = true;
  exists.insert(w[0]);
  for (int i = 1; i < N; i++) {
    cin >> w[i];
    if (!exists.count(w[i]) && w[i - 1][w[i - 1].size() - 1] == w[i][0]) {
      exists.insert(w[i - 1]);
    } else {
      succ = false;
    }
  }
  if (succ)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}