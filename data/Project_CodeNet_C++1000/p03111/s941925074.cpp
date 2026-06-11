#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  vll l(n);
  for (ll i = 0; i < n; i++) cin >> l[i];

  vll v(n, 0);
  ll ans = inf;
  for (ll i = 0; i < pow(4, n); i++) {
    ll subans = 0;
    vll cnt(4, 0), abc(4, 0);
    for (ll j = 0; j < n; j++) {
      cnt[v[j]]++;
      abc[v[j]] += l[j];
    }
    if (abc[1] > 0 && abc[2] > 0 && abc[3] > 0) {
      subans += abs(a - abc[1]);
      subans += abs(b - abc[2]);
      subans += abs(c - abc[3]);
      for (ll j = 1; j <= 3; j++) {
        subans += 10 * (cnt[j] - 1);
      }
      ans = min(ans, subans);
    }

    if (i == pow(4, n) - 1) break;
    ll x = n - 1;
    while (v[x] == 3) {
      v[x] = 0;
      x--;
    }
    v[x]++;
  }
  cout << ans << endl;
}