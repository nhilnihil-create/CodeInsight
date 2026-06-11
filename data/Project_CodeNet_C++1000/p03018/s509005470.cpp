#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  string s;
  cin >> s;
  ll res = 0, start = 0, size = (ll)s.size();
  for (ll i=0; i<size-2; i++) {
    if (s[i]!='A') start = i+1;
    else if (s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') {
      res += i-start+1;
      s[start] = 'B';
      s[start+1] = 'C';
      ll cnt = 0;
      for (ll j=i+2; j>=start+2; j--) {
        s[j] = 'A';
        cnt++;
        if (cnt>=3) break;
      }
      start += 2;
    }
  }
  cout << res << endl;
  return 0;
}