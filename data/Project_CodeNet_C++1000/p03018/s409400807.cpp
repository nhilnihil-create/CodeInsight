#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int> 
#define pdd pair<ld, ld> 
#define pb push_back
#define reset(x,v) memset(x,v,sizeof(x))
#define mod 998244353
using namespace std;

int main(){
	FASTIO
  string s;
  cin >> s;
  int n = s.size();
  string t;
  for (int i = 0; i < n; ++i) {
    if (i < (n - 1) && s[i] == 'B' && s[i + 1] == 'C') {
      t += 'D';
      ++i;
    } else {
      t += s[i];
    }
  }
  // cout << t << endl;

  n = t.size();
  ll answer = 0;
  ll count = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 'A') {
      count++;
    } else if (t[i] == 'D') {
      answer += count;
    } else {
      count = 0;
    }
  }
  cout << answer << endl;
  return 0;
}