#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int N,M,k,s;
  vector<int> S[10];
  int P[10];
  cin >> N >> M;
  rep(i, M) {
    cin >> k;
    rep(j, k) {
      cin >> s;
      S[i].push_back(--s);
    }
  }
  rep(i,M) {
    cin >> P[i];
  }

  int ans = 0;
  rep(i, (1 << N)) {
    bool flag=true;
    rep(j, M) {
      int sum = 0;
      rep(k, S[j].size()) {
        if(i & (1 << S[j][k])) sum++;
      }
      if(sum%2 != P[j]) flag=false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
