#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = 0;
  for (int i = 1; i <= N; i++) {
    ll out = 1;
    ll tmp = i;
    ll cnt = 0;
    while (tmp < K) {
      tmp *= 2;
      cnt++;
    }
    for (int i = 0; i < cnt; i++) {
      out *= 0.5;
    }
    res += out/N;
  }
  cout << fixed << setprecision(11) << res << endl;
  return 0;
}