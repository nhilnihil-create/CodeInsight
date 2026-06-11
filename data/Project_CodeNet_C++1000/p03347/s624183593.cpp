#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 200010;
ll A[MAXN];
int n;

void solve () {
  if (A[0]) {
    cout << -1 << endl;
    return;
  }

  for (int i=1;i<n;i++) {
    if (A[i] != 1 && A[i-1] + 1 < A[i]) {
      cout << -1 << endl;
      return;
    }
  }

  ll cnt = 0;
  ll ans = 0;
  ll prev = 0;
  for (int i=0;i<n;i++) {
    if (A[i] <= prev) {
      ans += prev;
    }
    prev = A[i];
  }
  ans += prev;
  cout << ans << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  solve();
}
