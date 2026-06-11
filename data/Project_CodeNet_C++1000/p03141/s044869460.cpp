#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> t(n);
  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    ll sum = a + b;
    t[i] = make_tuple(sum, a, b);
  }
  sort(ALL(t));

  ll sumT = 0, sumA = 0;
  REPR(i, n - 1) {
    ll sum, a, b;
    tie(sum, a, b) = t[i];
    if (n % 2 == 0) {
      if (i % 2 != 0) {
        sumT += a;
      } else {
        sumA += b;
      }
    } else {
      if (i % 2 == 0) {
        sumT += a;
      } else {
        sumA += b;
      }
    }
  }

  cout << sumT - sumA << endl;
  return 0;
}