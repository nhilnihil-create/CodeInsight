#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);

void solve() {
  string s;
  cin >> s;

  int w;
  cin >> w;
  string ans;
  int n = s.size();
  for (int i= 0; i < n; i+=w) {
    ans += s[i];
  }

  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
