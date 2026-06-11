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
  string s;
  cin >> N >> s;
  ll r_cnt = 0, b_cnt = 0;
  for (auto c : s) {
    if (c == 'R')
      r_cnt++;
    else
      b_cnt++;
  }
  if (r_cnt > b_cnt) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}