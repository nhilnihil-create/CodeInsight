#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  int a = 0, b = 0, c = 0;
  rep(i, N) {
    if (P[i] <= A)
      a++;
    else if (P[i] <= B)
      b++;
    else
      c++;
  }
  cout << min({a, b, c}) << endl;
  return 0;
}