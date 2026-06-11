#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  string s; cin >> s;
  int sz = s.size();
  char mid = s[sz/2];
  int left = sz/2 - 1;
  int right = (sz-1) - left;
  int ans = (sz+1)/2;
  rep(i,sz/2) {
    if (s[left-i] != mid || s[right+i] != mid) break;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
