#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N;
  cin >> N;
  int res = N;
  for (int i=0; i<=N; i++) {
    int tmp = 0, t = i;
    while (t>0) {
      tmp += t%6;
      t /= 6;
    }
    t = N-i;
    while (t>0) {
      tmp += t%9;
      t /= 9;
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}