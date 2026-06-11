#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int ans = 0;
  int N;
  cin >> N;
  ll A[N];
  map<ll,ll> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }
  sort(A,A+N);
  for (int bit = 32; bit >= 1; bit--) {
    for (int i = 0; i < N; i++) {
      if (lower_bound(A,A+N,(1LL << bit) - A[i]) == upper_bound(A,A+N,(1LL << bit) - A[i])) {
        continue;
      }
      ll& p = mp[A[i]];
      ll& q = mp[(1LL << bit) - A[i]];
      if ((1LL << (bit-1)) == A[i]) {
        ll s = p / 2;
        if (s > 0) {
          ans += s;
          p -= s*2;
        } 
      } else {
        ll s = min(p,q);
        if (s > 0) {
          ans += s;
          p -= s;
          q -= s;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}