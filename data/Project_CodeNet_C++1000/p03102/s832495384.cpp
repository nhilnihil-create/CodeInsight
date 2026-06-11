#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int n,m,c;
  cin >> n >> m >>c;
  vector<int> b(m);
  rep(i,0,m) cin >> b[i];
  ll ans=0;
  rep(i,0,n){
    vector<int> a(m);
    rep(j,0,m) cin >> a[j];
    ll total=0;
    rep(j,0,m){
      total+= a[j]*b[j];
    }
    total +=c;
//    cout << total << endl;
    if(total>0) ans++;
  }
  cout << ans << endl;

  return 0;
}