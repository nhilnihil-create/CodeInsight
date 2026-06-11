#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
using namespace std;
using ll = long long;
int main () {
  int n;
  cin >> n;
  vector<ll> cnt(5);
  rep(i,0,n) {
    string s;
    cin >> s;
    if (s[0] == 'M') cnt[0]++;
    if (s[0] == 'A') cnt[1]++;
    if (s[0] == 'R') cnt[2]++;
    if (s[0] == 'C') cnt[3]++;
    if (s[0] == 'H') cnt[4]++;
  }
  ll ans = 0;
  rep(i,0,3) rep(j,i+1,4) rep(k,j+1,5) {
    ans += cnt[i] * cnt[j] * cnt[k];
  }
  cout << ans << endl;
}