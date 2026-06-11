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

int A[20][20];

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  rep(i,M) cin >> B[i];
  rep(i,N) rep(j,M) cin >> A[i][j];
  int ans = 0;
  rep(i,N) {
    int temp = 0;
    rep(j,M) temp += A[i][j] * B[j];
    if (temp + C > 0) ++ans;
  }
  cout << ans << endl;
  return 0;
}