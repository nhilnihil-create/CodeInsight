#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  map<char, ll> mp;
  rep(i, N) {
    string s;
    cin >> s;
    mp[s[0]]++;
  }

  vector<ll> cnt(5);
  cnt[0] = mp['M'];
  cnt[1] = mp['A'];
  cnt[2] = mp['R'];
  cnt[3] = mp['C'];
  cnt[4] = mp['H'];

  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      for (int k = j+1; k < 5; k++) {
        ans += (cnt[i] * cnt[j] * cnt[k]);
      }
    }
  }

  cout << ans << endl;
  return 0;
}