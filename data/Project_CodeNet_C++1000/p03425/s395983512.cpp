#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int N;
  cin >> N;
  map<char, ll> mp;
  rep(i, N) {
    string S;
    cin >> S;
    mp[S[0]]++;
  }

  ll ans = 0;
  ans += mp['M'] * mp['A'] * mp['R'];
  ans += mp['M'] * mp['A'] * mp['C'];
  ans += mp['M'] * mp['A'] * mp['H'];
  ans += mp['M'] * mp['R'] * mp['C'];
  ans += mp['M'] * mp['R'] * mp['H'];
  ans += mp['M'] * mp['C'] * mp['H'];
  ans += mp['A'] * mp['R'] * mp['C'];
  ans += mp['A'] * mp['R'] * mp['H'];
  ans += mp['A'] * mp['C'] * mp['H'];
  ans += mp['R'] * mp['C'] * mp['H'];

  cout << ans << endl;
  
  return 0;
}