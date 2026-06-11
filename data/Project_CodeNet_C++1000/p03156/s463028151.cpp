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
  ll n, a, b;
  cin >> n >> a >> b;
  vll p(n);
  ll x = 0, y = 0, z = 0;
  for (ll i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] <= a) x++;
    else if (p[i] <= b) y++;
    else z++;
  }
  cout << min({x, y, z}) << endl;
}