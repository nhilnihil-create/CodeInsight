#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

ll N, A[200020];
map<ll,ll> m;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
    ++m[A[i]];
  }
  sort(A, A + N, greater<ll>());

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    if(m[A[i]] == 0) continue;

    // Ai < 2^n <= Ai*2
    ll j = 1;
    while(j <= A[i]) j <<= 1;
    if(A[i] * 2 == j) {
      if(m[A[i]] > 1) {
        ans += m[A[i]] / 2;
        m[A[i]] %= 2;
      }
    } else if(m[j - A[i]] > 0) {
      ans += min(m[A[i]], m[j - A[i]]);
      if(m[A[i]] >= m[j - A[i]]) {
        m[A[i]] -= m[j - A[i]]; m[j - A[i]] = 0;
      } else {
        m[j - A[i]] -= m[A[i]]; m[A[i]] = 0;
      }
    }
  }
  cout << ans;
  return 0;
}