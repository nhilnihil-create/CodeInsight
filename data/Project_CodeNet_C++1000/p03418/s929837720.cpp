#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
ll llmax = LLONG_MAX;
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
vi d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  ll n, k;
  cin >> n >> k;
  if (k == 0) cout << n * n << endl;
  else {
    ll ans = 0;
    for (ll b = k + 1; b <= n; b++) {
      ans += (b - k) * floor((double)n / b);
      if (n % b >= k) ans += n % b - k + 1;
    }
    cout << ans << endl;
  }
}