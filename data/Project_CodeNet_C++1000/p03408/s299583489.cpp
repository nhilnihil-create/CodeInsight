#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i, N) cin >> s[i];
  int M;
  cin >> M;
  vector<string> t(M);
  rep(i, M) cin >> t[i];
  
  int ans=0;
  int curr=0;
  
  rep(i, N) {
    curr=0;
    rep(j, N) {
      if (s[i] == s[j]) curr++;
    }
    rep(j, M) {
      if (s[i] == t[j]) curr--;
    }
    if (ans<curr) ans=curr;
  }
  cout << ans << endl;
}
