#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, k;
  string s;
  cin >> n >> k >> s;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vll a(0);
  ll cnt = 1;
  for (ll i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      a.push_back(cnt);
      cnt = 1;
    }
    else cnt++;
  }
  a.push_back(cnt);
  for (ll i = 1; i < a.size(); i++) a[i] += a[i - 1];

  ll ans = 0;
  if (s[0] == '1') {
    if (k >= a.size() / 2) ans = n;
    else {
      ans = a[min((ll)a.size() - 1, 2 * k)];
      for (ll i = 2; i < a.size(); i += 2) ans = max(ans, a[min((ll)a.size() - 1, i + 2 * k)] - a[i - 1]);
    }
  }
  else {
    if (a.size() % 2 == 1) {
      if (k >= a.size() / 2 + 1) ans = n;
      else {
        ans = a[min((ll)a.size() - 1, 2 * k - 1)];
        for (ll i = 1; i < a.size(); i += 2) ans = max(ans, a[min((ll)a.size() - 1, i + 2 * k)] - a[i - 1]);
      }
    }
    else {
      if (k >= a.size() / 2) ans = n;
      else {
        ans = a[min((ll)a.size() - 1, 2 * k - 1)];
        for (ll i = 1; i < a.size(); i += 2) ans = max(ans, a[min((ll)a.size() - 1, i + 2 * k)] - a[i - 1]);
      }
    }
  }
  cout << ans << endl;
}