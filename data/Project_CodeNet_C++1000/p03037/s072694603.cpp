#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<int> l(m),r(m); rep(i,m) cin >> l[i] >> r[i];

  int left = 1,right = n;

  rep(i,m){
    left = max(left,l[i]);
    right = min(right,r[i]);
  }
  int ans = left>right ? 0:right-left+1;

  cout << ans << endl;
  
  return 0;
}
