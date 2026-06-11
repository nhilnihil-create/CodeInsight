#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

vector<int> prime_factors(ll n) {
  vector<int> ret;
  while (n >= 4) {
    if (n % 2) {
      break;
    } else {
      n /= 2;
      ret.push_back(2);
    }
  }
  ll i = 3;
  while (n >= i * i) {
    if (n % i) {
      i += 2;
    } else {
      n /= i;
      ret.push_back(i);
    }
  }
  ret.push_back(n);
  return ret;
}

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<long> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  int ans = 0;
  rep(i, 0, N) {
    if (A[i] % 2 == 0) {
      vector<int> p;
      p = prime_factors(A[i]);
      ans += count(all(p), 2);
    }
  }
  cout << ans << endl;
  return 0;
}
