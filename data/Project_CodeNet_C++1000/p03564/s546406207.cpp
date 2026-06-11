#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (i=0; i<n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  int i, ans;
  ans=1;
  rep(i, n) {
    if (ans > k) {
      ans+=k;
    } else {
      ans*=2;
    }
  }
  cout << ans << endl;
}
  