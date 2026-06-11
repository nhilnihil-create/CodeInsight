#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

string int_to_basem2(ll n) {
  if (n == 0) {
    return "0";
  }

  string retv = "";
  while (n != 0) {
    ll remain = ((n % 2LL) + 2LL) % 2LL;
    char digit = (char)remain + '0';

    retv.insert(retv.begin(), digit);
    n = (n - remain) / (-2LL);
  }

  return retv;
}

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  // main procedure
  string ans = int_to_basem2(N);

  // output
  cout << ans << endl;

  return 0;
}