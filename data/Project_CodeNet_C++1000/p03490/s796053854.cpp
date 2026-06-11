#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 8005;

vector<int> _dp;
vector<int> _ldp;

int& dp (int x) {
  return _dp[MAX_N + x];
}

int& ldp (int x) {
  return _ldp[MAX_N + x];
}

bool knapsack (vector<int> v, int t) {
  _dp = vector<int> (2 * MAX_N + 5);
  dp(0) = 1;

  for (int u : v) {
    _ldp = _dp;
    for (int i = -MAX_N; i <= MAX_N; i++) {
      dp(i) = 0;
    }

    for (int i = -MAX_N; i <= MAX_N; i++) {
      if (ldp(i)) {
        dp(i - u) = 1;
        dp(i + u) = 1;
      }
    }
  }

  return dp(t);
}

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  
  int x, y;
  cin >> x >> y;

  vector<int> xs;
  vector<int> ys;
  int cur = -1;

  for (char c : s) {
    if (c == 'F') {
      if (cur == -1) x--;
      else if (cur == 0) xs.back()++;
      else if (cur == 1) ys.back()++;
    } else {
      if (cur == 1) {
        xs.push_back(0);
        cur = 0;
      } else {
        ys.push_back(0);
        cur = 1;
      }
    }
  }

  if (knapsack(xs, x) && knapsack(ys, y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
