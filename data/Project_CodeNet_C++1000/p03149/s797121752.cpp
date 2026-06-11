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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vll v(10, 0);
  v[a]++;
  v[b]++;
  v[c]++;
  v[d]++;
  if (v[1] == v[9] && v[9] == v[7] && v[7] == v[4] && v[4] == 1) YES();
  else NO();
}