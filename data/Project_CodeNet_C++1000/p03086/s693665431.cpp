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
  string S;
  cin >> S;
  int ans = 0;
  int t = 0;
  rep(i, S.size()) {
    if (S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C') {
      ++t;
    }
    else {
      ans = max(ans, t);
      t = 0;
    }
  }
  ans = max(t, ans);
  cout << ans << endl;
  return 0;
}