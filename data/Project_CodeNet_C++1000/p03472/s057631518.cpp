// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<ll, ll> P;

int main() {
  ll n, h; cin >> n >> h;
  vector<P> A(n);
  loop(i,0,n) cin >> A[i].first >> A[i].second;
  sort(A.rbegin(), A.rend());
  ll max_a = A[0].first;
  ll cnt = 0;
  ll sum = 0;
  sort(A.rbegin(), A.rend(), [](const P a, const P b) {
    return a.second < b.second;
  });
  for (auto &&p: A) {
    if (p.second > max_a) {
      cnt++;
      sum += p.second;
      if (sum >= h) {
        cout << cnt << endl;
        return 0;
      }
    }
  }
  h -= sum;
  cout << cnt + h/max_a + (h%max_a != 0) << endl;
  return 0;
}
