#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  int maxv = 0;
  rep(i, n) {
    chmax(maxv, b[i]);
  }
  vector<int> ans;
  rep(i, n) {
    int t = -1;
    rep(j, b.size()) {
      if(b[j] == j + 1) t = b[j];
    }
    if (t == -1) {
      puts("-1");
      return 0;
    }

    ans.push_back(t);
    b.erase(b.begin() + t - 1);
  }
  reverse(ans.begin(), ans.end());
  rep(i, n) printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
}