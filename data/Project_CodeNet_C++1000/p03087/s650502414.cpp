#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

using pi = pair<int, int>;
using pll = pair<ll, ll>;

constexpr auto MOD = 1e9 + 7;
constexpr auto INF = 0x3f3f3f3f;

#define rep(i, a, b) for (auto i = a; i < b; ++i)

template <class T> inline T square(T x) { return x * x; };

template <class T> void print(const T &val) { cout << val << '\n'; }

template <class Iterator> void print(Iterator begin, Iterator end) {
  for (auto it = begin; it != end; ++it) {
    cout << *it << ' ';
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int q;
  cin >> q;

  string s;
  cin >> s;

  vector<int> dp(n + 1, 0);

  for (auto i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    if (s[i - 1] == 'A' && s[i] == 'C') {
      dp[i]++;
    }
  }

  for (auto i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;

    print(dp[y - 1] - dp[x - 1]);
  }
}

