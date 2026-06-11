#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
ll llmax = LLONG_MAX;
vll d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  ll n, k;
  cin >> n >> k;
  if (k % 2 == 0) {
    ll ans1 = 0, ans2 = 0;
    for (ll i = 1; i <= n; i++) {
      if (i % k == 0) ans1++;
      else if (i % k == k / 2) ans2++;
    }
    cout << (ll)(pow(ans1, 3) + pow(ans2, 3)) << endl;
  }
  else {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      if (i % k == 0) ans++;
    }
    cout << (ll)pow(ans, 3) << endl;
  }
}