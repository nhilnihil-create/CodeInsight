#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  vector<int> a = {1, 9, 7 ,4};
  vector<bool> ok(4);
  rep(i, 4) {
    int t;
    cin >> t;
    rep(j, 4) {
      if(t == a[j]) ok[j] = true;
    }
  }

  bool ans = true;
  rep(i, 4) if(!ok[i]) ans = false;
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}