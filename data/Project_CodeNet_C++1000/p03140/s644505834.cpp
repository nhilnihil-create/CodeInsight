#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] == b[i] && b[i] == c[i]) {}
    else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) ans++;
    else ans += 2;
  }
  cout << ans << endl;
}