#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string n;
  cin >> n;
  int max_sum = 0;
  rep(i, n.size() + 1) {
    int now_sum = 0;
    rep(j, n.size()) {
      if (j < i) now_sum += n[j] - '0';
      else if (j == i) now_sum += n[j] - '0' - 1;
      else now_sum += 9;
    }
    max_sum = max(max_sum, now_sum);
  }
  cout << max_sum << endl;
  return 0;
}