#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int mini = 1001001001;
    ll sum = 0;
    rep(i,n) {
      int a;
      cin >> a;
      if (a < 0) cnt++;
      a = abs(a);
      sum += a;
      mini = min(mini, a);
    }
    if (cnt%2 == 0) cout << sum << endl;
    else cout << sum-mini*2 << endl;
    return 0;
}