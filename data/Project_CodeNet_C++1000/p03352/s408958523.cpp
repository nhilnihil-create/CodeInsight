#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;
  int maxm = -1;
  for(int b = 1; b*b <= x; b++) {
    for(int q = 2; q <= 10; q++) {
      int ans = 1;
      rep(i, q) {
        ans *= b;
      }
      if(ans <= x) maxm = max(maxm, ans);
    }
  }
  cout << maxm << endl;
  return 0;
}
  