#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  cout << "Christmas";
  for (ll i = 25; i > n; i--) {
    cout << " Eve";
  }
  cout << endl;
}