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

vector<int> Eratosthenes(const int N) {
  vector<bool> is_prime(N + 1);
  for (int i = 0; i <= N; ++i) {
    is_prime[i] = true;
  }
  vector<int> P;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= N; j += i) {
        is_prime[j] = false;
      }
      P.emplace_back(i);
    }
  }
  return P;
}

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<int> p = Eratosthenes(100000);
  vector<int> n2017;
  for (int i : p) {
    int n = (i + 1) / 2;
    if (binary_search(all(p), n)) n2017.push_back(i);
  }

  int Q;
  cin >> Q;
  rep(_, 0, Q) {
    int l, r;
    cin >> l >> r;
    int left = lower_bound(all(n2017), l) - n2017.begin();
    int right = upper_bound(all(n2017), r) - n2017.begin();
    cout << right - left << endl;
  }
  return 0;
}
