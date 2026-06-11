#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

template<int MOD> struct MInt {
  long long val;
  constexpr MInt(long long val = 0) : val(val % MOD) { if (val < 0) val += MOD; }
  MInt operator+(const MInt& n) const { return MInt(val) += n; }
  MInt& operator+=(const MInt& n) { val = (val + n.val) % MOD; return *this; }
  friend ostream& operator<<(ostream& os, const MInt& n) { os<<n.val; return os; }
};
constexpr int MOD = 1e9+7;
using mint = MInt<MOD>;

int main() {
  int in(N);

  stack<int> v;
  rep(i, N) {
    int in(c);
    if (v.empty() || v.top() != c)
      v.push(c);
  }
  map<int, int> m;
  vector<mint> dp(N+1, 0);
  map<int, mint> sum;
  mint ans;

  rep(i, v.size()) {
    int c = v.top(); v.pop();
    ans = dp[i+1] = dp[i] + m[c] + sum[c];
    sum[c] += dp[i];
    ++m[c];
  }
  cout << ans + 1 << endl;

  return 0;
}
