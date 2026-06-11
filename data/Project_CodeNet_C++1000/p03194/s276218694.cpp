#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  ll N; cin >> N;
  ll P; cin >> P;

  ll ans = 1;
  for(auto x: prime_factor(P)) {
    if(x.second / N >= 1) ans *= pow(x.first, x.second / N);
  }

  cout << ans << endl;
}