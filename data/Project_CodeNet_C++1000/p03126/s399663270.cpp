#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,ll>;
const ll inf=1000000000007;
const int mod=1000000007;


int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);

  rep(i,0,n){
    int k;
    cin >> k;
    rep(j,0,k){
      int ak;
      cin >> ak;
      ak--;
      a[ak]++;
    }
  }
  int ans=0;
  rep(i,0,m){
    if(a[i]==n) ans++;
  }
  cout << ans << endl;


  return 0;

}
