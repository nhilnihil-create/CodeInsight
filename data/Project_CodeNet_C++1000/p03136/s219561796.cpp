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
  int N; cin >> N;
  vector<int> L(N);
  int sum = 0;
  rep(i,N) {
    cin >> L[i];
    sum += L[i];
  }
  bool ok = true;
  rep(i,N) {
    if (sum - L[i] <= L[i]) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}