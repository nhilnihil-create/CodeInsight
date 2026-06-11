#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  string S, T;
  cin >> S >> T;

  set<ll> s;
  mll m;
  bool ok = true;
  for (ll i = 0; i < S.size(); ++i) {
    ll b = S[i] - 'a' + 1;
    ll a = T[i] - 'a' + 1;

    if (m[b] == 0) {
      m[b] = a;
      if ((s.find(a) != s.end())) {
        ok = false;
        break;
      }
      s.insert(a);
    } else {
      if (m[b] != a) {
        ok = false;
        break;
      }
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
