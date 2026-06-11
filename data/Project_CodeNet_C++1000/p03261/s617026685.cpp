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
  bool ok = true;

  ll N;
  scanf("%lld", &N);

  string s;
  cin >> s;

  map<string, ll> m;
  m[s] = 1;

  for (ll i = 1; i < N; i++) {
    string ss;
    cin >> ss;

    if (s[s.size() - 1] == ss[0] && m[ss] == 0) {
      // ok
    } else {
      ok = false;
      break;
    }
    m[ss] = 1;
    s = ss;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
