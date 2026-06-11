#include <bits/stdc++.h>
using namespace std;

#define RFOR(type, i, a, b) for (type i = (b)-1;i >= (a); --i)
#define REP(type, i, n) for (type i = 0; i < (n); ++i)

int main(void) {
  long N, Q; cin >> N >> Q;
  string s; cin >> s;
  vector<pair<char, char> > input(Q);
  REP(long, i, Q) {
    char t, d; cin >> t >> d;
    input.at(i) = make_pair(t, d);
  }

  long l = -1, r = N;
  RFOR(long, i, 0, Q) {
    char t = input.at(i).first, d = input.at(i).second;
    if (d == 'L') {
      if (l < N-1 && t == s[l+1]) l++;
      if (r < N && t == s[r]) r++;
    } else {
      if (l > -1 && t == s[l]) l--;
      if (r > 0 && t == s[r-1]) r--;
    }
  }
  cout << r-l-1 << endl;

  return 0;
}
