#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll A[200010];
using P = pair<ll, ll>;
P L[200010], R[200010];

void func(P *X) {
  int l = 0, r = 1;
  ll sumL = A[l], sumR = 0;
  while (r < N) {
    sumR += A[r];
    while (l+1 < r) {
      ll tmp = abs(sumL - sumR + 2 * A[l+1]);
      if (tmp > abs(sumL - sumR)) break;
      sumL += A[l+1];
      sumR -= A[l+1];
      l++;
    }
    X[r++] = P(min(sumL, sumR), max(sumL, sumR));
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  func(L);
  reverse(A, A+N);
  func(R);
  reverse(A, A+N);
  reverse(R, R+N);
  ll ans = 1LL << 60;
  for (int i = 1; i+2 < N; i++) {
    ll mn = min(L[i].first, R[i+1].first);
    ll mx = max(L[i].second, R[i+1].second);
    ans = min(ans, mx - mn);
  }
  cout << ans << endl;

  return 0;
}