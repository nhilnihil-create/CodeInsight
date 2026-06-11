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
  vll v(4, 0);
  for (ll i = 0; i < 6; i++) {
    ll a;
    cin >> a;
    v[a - 1]++;
  }
  ll cnt = 0;
  for (ll i = 0; i < 4; i++) {
    if (v[i] == 2) cnt++;
  }
  if (cnt == 2) YES();
  else NO();
}