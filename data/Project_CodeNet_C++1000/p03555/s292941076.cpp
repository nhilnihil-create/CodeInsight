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
  vector<string> C(2);
  cin >> C[0] >> C[1];
  reverse(C[1].begin(), C[1].end());
  if (C[0] == C[1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}