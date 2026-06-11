//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
using P=pair<int,int>;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,k,ans=0;
  cin >> n >> k;
  if(k==0) {
    cout << n*n << endl;
    return 0;
  }
  /*k=2,b=3のとき
  a=1,2,3|4,5,6|7,8...
    1,2,0|1,2,0|1,2,0...*/
  for(int i=k+1; i<=n; i++) {
    ans+=n/i*(i-k)+max(0LL,n%i-k+1);
  }
  cout << ans << endl;
}
