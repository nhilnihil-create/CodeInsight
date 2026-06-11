#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  cin >> n;
  ll ans = inf;
  for (ll i = 1; i < n; i++) {
    ll a = i, b = n - i;
    string s = to_string(a), t = to_string(b);
    ll sum = 0;
    for (ll j = 0; j < s.size(); j++) {
      sum += s[j] - '0';
    }
    for (ll j = 0; j < t.size(); j++) {
      sum += t[j] - '0';
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}