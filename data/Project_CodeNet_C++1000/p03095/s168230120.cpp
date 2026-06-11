#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
const int MOD = 1e9+7; 
int main() {
  string s;
  int n;
  cin >> n >> s;
  map<char, int> d;
  rep(i,n) {
    d[s[i]]++;
  }
  ll ans = 1;
  rep(i,26) {
    char c = 'a' + i;
    if (d[c] == 0) continue;
    ans *= (d[c]+1);
    ans %= MOD;
  }
  ans--;
  cout << ans << endl;
  return 0;
}