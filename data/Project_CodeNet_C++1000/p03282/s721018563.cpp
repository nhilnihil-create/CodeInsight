#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  string s;
  ll k;
  cin >> s >> k;
  --k;
  char res = '1';
  ll n = s.size();
  rep(i,min(n,k+1)){
    if(s[i]!='1'){
      res = s[i];
      break;
    }
  }
  cout << res << endl;
}
