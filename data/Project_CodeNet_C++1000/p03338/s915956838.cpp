#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N; string S;
  cin >> N >> S;

  int ans = 0;
  rep(i,1,N-1) {
    set<char> a, b;
    rep(j,0,N-1) {
      if (j < i) a.insert(S[j]);
      else b.insert(S[j]);
    }

    vector<char> v;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));

    ans = max(ans, int(v.size()));
  }

  cout << ans << endl;
  return 0;
}
