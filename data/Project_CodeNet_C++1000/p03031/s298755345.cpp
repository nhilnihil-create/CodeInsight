#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> S;
  rep(i,0,M-1) {
    int k;
    cin >> k;
    vector<int> s(k);
    rep(j,0,k-1) {
      cin >> s[j];
      --s[j];
    }
    sort(s.begin(), s.end());
    S.push_back(s);
  }

  vector<int> P(M);
  rep(i,0,M-1) {
    cin >> P[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); ++i) {
    vector<int> switches;
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        switches.push_back(j);
      }
    }

    sort(switches.begin(), switches.end());

    bool ok = true;
    for (int j = 0; j < M; ++j) {
      vector<int> s = S[j];
      vector<int> v;
      set_intersection(switches.begin(), switches.end(), s.begin(), s.end(), back_inserter(v));
      if (v.size() % 2 != P[j])
        ok = false;
    }

    if (ok)
      ans++;
  }
  
  cout << ans << endl;
  return 0;
}
