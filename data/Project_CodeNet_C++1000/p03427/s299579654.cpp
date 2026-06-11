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
  string s;
  cin >> s;
  ll ans = 9 * (s.size() - 1);
  ans += s[0] - '0' - 1;
  for (ll i = 1; i < s.size(); i++) {
    if (s[i] != '9') break;
    if (i == s.size() - 1) ans++;
  }
  if (s.size() == 1) ans ++;
  cout << ans << endl;
}