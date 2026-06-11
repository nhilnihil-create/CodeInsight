#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vl cum(n + 1);
  cum[0] = 0LL;
  REP(i, n) {
    cin >> cum[i + 1];
    cum[i + 1] += cum[i];
  }

  vl s;
  REP(i, n) {
    FOR(j, i, n + 1) { s.push_back(cum[j] - cum[i]); }
  }

  vi bit(41, 0);
  int m = s.size();
  REP(i, m) {
    ll tmp = s[i];
    int c = 0;
    while (tmp != 0) {
      tmp /= 2;
      c++;
    }
    bit[c]++;
  }

  int sum = 0;
  int ki = 0;
  for (int i = 40; i >= 0; i--) {
    sum += bit[i];
    if (sum >= k) {
      ki = i;
      break;
    }
  }

  vl tv;
  REP(i, m) {
    if ((s[i] & (1LL << (ki - 1))) != 0) {
      tv.push_back(s[i]);
    }
  }
  ll ans = (1LL << (ki - 1));
  ki--;

  for (int i = ki; i >= 1; i--) {
    vl ttv;
    ll mask = (1LL << (i - 1));
    REP(i, tv.size()) {
      if ((mask & tv[i]) != 0LL) {
        ttv.push_back(tv[i]);
      }
    }
    if (ttv.size() >= k) {
      ans += mask;
      tv = ttv;
    }
  }

  cout << ans << endl;
}
