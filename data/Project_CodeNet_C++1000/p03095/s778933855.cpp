#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, p = 1e9 + 7;
  string s;
  cin >> n >> s;

  vll cnt(26, 1);
  for (ll i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }

  ll ans = 1;
  for (ll i = 0; i < 26; i++) {
    ans *= cnt[i];
    ans %= p;
  }
  ans--;
  if (ans < 0) ans += p;
  cout << ans << endl;
}