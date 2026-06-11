#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 200010;
ll A[MAXN];
int n;

void solve () {
  ll ans = 0;
  ll prev = 0;
  bool check = false;
  if (A[0]) {
    check = true;
  }

  for (int i=1;i<n;i++) {
    if (A[i] != 1 && A[i-1] + 1 < A[i]) {
      check = true;
      break;
    }
  }
  if (check) {
    cout << -1 << endl;
    return;
  }

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
