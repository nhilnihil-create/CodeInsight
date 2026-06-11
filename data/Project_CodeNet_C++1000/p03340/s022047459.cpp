#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;
  ll sum = 0;
  int right = 0;

  rep(left, N) {
    while(right < N && (sum ^ A[right]) == sum + A[right]) {
      sum += A[right];
      right++;
    }

    ans += right - left;
    sum -= A[left];
  }

  cout << ans << endl;
}
