#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
const ll MAX = 2*(ll)pow(10, 5);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b, k; cin >> a >> b >> k;
  ll tmp = 0;
  for (ll i = min(a, b); i >= 1; i--) {
    if (a%i==0 && b%i==0) tmp++;
    if (tmp == k) {
      cout << i << endl;
      break;
    }
  }
}