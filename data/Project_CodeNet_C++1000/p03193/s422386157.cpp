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
  ll n, h, w;
  cin >> n >> h >> w;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    //cout << h - a << " " << w - b << endl;
    if (a >= h && b >= w) ans++;
  }
  cout << ans << endl;
}