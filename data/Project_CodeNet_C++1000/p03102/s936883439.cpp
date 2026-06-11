#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m,c; cin >> n >> m >> c;
  vector<int> b(m); rep(i,m) cin >> b[i];
  vector<vector<int>> a(n,vector<int>(m));
  rep(i,n)
    rep(j,m) cin >> a[i][j];

  int ans = 0;
  rep(i,n){
    int tmp = 0;
    rep(j,m) tmp+=a[i][j]*b[j];
    tmp+=c;
    if(tmp>0) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
