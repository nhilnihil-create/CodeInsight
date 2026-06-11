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
  // 完全グラフから消していく
  vector<P> ans;
  if(n % 2) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if(n - i == j) continue;
        int a, b;
        a = i; b = j;
        ans.push_back(P(a, b));
      }
    }
    
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if(n - i + 1 == j) continue;
        int a, b;
        a = i; b = j;
        ans.push_back(P(a, b));
      }
    }
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}