#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main() {
  int n;
  cin >> n;

  string result = "No";
  rep(i,n) {
    rep(j,n) {
      if (n == 4*i + 7*j) result = "Yes";
    }
  }

  cout << result << endl;
  return 0;
}