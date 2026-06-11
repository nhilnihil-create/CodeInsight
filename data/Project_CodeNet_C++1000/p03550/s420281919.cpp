#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
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
  ll n, z, w;
  cin >> n >> z >> w;
  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  ll ans = abs(a[n - 1] - w);
  if (n >= 2) ans = max(ans, abs(a[n - 2] - a[n - 1]));
  cout << ans << endl; 
}