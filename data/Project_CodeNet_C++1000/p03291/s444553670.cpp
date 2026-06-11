#include <iostream>
#include <map>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

template<int MOD> struct MInt {
  long long val;
  MInt(long long val = 0) : val(val % MOD) { if (val < 0) val += MOD; }
  MInt operator+(const MInt& n) const { return MInt(val) += n; }
  MInt operator*(const MInt& n) const { return MInt(val) *= n; }
  MInt& operator+=(const MInt& n) { val = (val + n.val) % MOD; return *this; }
  MInt& operator*=(const MInt& n) { val = (val * n.val) % MOD; return *this; }
  bool operator==(const MInt& n) { return val == n.val; }
  bool operator!=(const MInt& n) { return val != n.val; }
  friend ostream& operator<<(ostream& os, const MInt& n) { os<<n.val; return os; }
};
const int MOD = 1e9+7;
using mint = MInt<MOD>;

int main() {
  string S; cin >> S;
  int N = S.size();

  map<string, mint> count;
  mint pow = 1;
  rep(i, N) {
    if (S[i] == 'C') { count["ABC"] += count["AB"]; }
    if (S[i] == 'B') { count["AB"] += count["A"]; }
    if (S[i] == 'A') { count["A"] += pow; }
    if (S[i] == '?') {
      count["ABC"] = count["ABC"] * 3 + count["AB"];
      count["AB"] = count["AB"] * 3 + count["A"];
      count["A"] = count["A"] * 3 + pow;
      pow *= 3;
    }
  }
  cout << count["ABC"] << endl;

  return 0;
}
