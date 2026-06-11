#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  string s;
  cin >> n >> s;

  string t;
  for (ll i = 0; i < n; i++) t.push_back('#');
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '.') ans++;
  }
  vll v(1, ans);
  for (ll i = 0; i < n; i++) {
    t[i] = '.';
    if (s[i] == '.') v.push_back(v.back() - 1);
    else v.push_back(v.back() + 1);
  }
  for (ll i = 1; i <= n; i++) ans = min(ans, v[i]);
  cout << ans << endl;
}