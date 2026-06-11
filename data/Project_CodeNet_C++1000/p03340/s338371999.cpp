#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0, p = A[0];
  int count = 1, left = 0;
  for (int i = 1; i < N; i++) {
    if ((p & A[i]) == 0) {
      count++;
      p ^= A[i];
    }
    else {
      ans += count;
      p -= A[left];
      count--;
      left++;
      i--;
    }
  }
  ans += 1LL * (count + 1) * count / 2;
  cout << ans << "\n";
}