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
  ll a, b, k;
  cin >> a >> b >> k;
  for (ll i = 0; i < k; i++) {
    if (i % 2 == 0) {
      if (a % 2 == 1) a--;
      a /= 2;
      b += a;
    }
    else {
      if (b % 2 == 1) b--;
      b /= 2;
      a += b;
    }
  }
  cout << a << " " << b << endl;
}