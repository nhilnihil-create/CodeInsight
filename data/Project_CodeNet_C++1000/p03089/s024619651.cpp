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
  ll n;
  cin >> n;

  vll b(n);
  for (ll i = 0; i < n; i++) cin >> b[i];

  vll ans(0);
  while (b.size()) {
    for (ll i = b.size() - 1; i >= 0; i--) {
      if (b[i] == i + 1) {
        b.erase(b.begin() + i);
        ans.push_back(i + 1);
        break;
      }
      if (i == 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (ll i = 0; i < n; i++) cout << ans[n - 1 - i] << endl;
}