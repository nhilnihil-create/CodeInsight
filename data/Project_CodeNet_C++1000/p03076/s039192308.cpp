#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
  fastIO;
  vector<int> time(5);
  rep(i, 5) cin >> time.at(i);

  int sum = 0, diff = 0;
  for(auto t: time) {
    sum += t;
    int mod = 10 - t % 10;
    if(mod != 10) {
      sum += mod;
      diff = max(diff, mod);
    }
  }

  cout << sum - diff << endl;
}
