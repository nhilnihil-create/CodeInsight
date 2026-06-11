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
  ll n = s.size();

  for (ll i = 0; i < n; i++) {
    for (ll j = i; j < n; j++) {
      string t = s;
      t.erase(t.begin() + i, t.begin() + j);
      if (t == "keyence") {
        YES();
        return 0;
      }
    }
  }
  NO();
}