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
  string s, t = "AKIHABARA";
  cin >> s;
  if (s.size() > 9) {
    NO();
    return 0;
  }
  ll j = 0;
  ll m;
  for (ll i = 0; i < s.size() && j < 9; i++) {
    if (s[i] == t[j]) {
      j++;
      m = i;
    }
    else if (t[j] == 'A') {
      i--;
      j++;
      m = i - 1;
    }
    else {
      NO();
      return 0;
    }
  }
  if (j <= 7) NO();
  else {
    for (ll i = m + 1; i < s.size(); i++) {
      if (s[i] != 'A') {
        NO();
        return 0;
      }
    }
    YES();
  }
}