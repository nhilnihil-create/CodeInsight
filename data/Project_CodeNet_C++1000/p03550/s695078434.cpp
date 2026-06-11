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
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  if (N == 1)
    cout << abs(a[0]-W) << endl;
  else
    cout << max({abs(a[N-1]-W), abs(a[N-2]-a[N-1])}) << endl;
  return 0;
}