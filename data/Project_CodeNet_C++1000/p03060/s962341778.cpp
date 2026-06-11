#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  vector<int> C(N);
  rep(i,N) cin >> V[i];
  rep(i,N) cin >> C[i];
  int ans = 0;
  rep(i,N) {
    if (V[i] - C[i] > 0) ans += V[i] - C[i];
  }
  cout << ans << endl;
  return 0;
}