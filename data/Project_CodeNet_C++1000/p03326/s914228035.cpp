/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
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
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,cnt=0,ans=0,x[1005]={},y[1005]={},z[1005]={};
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  for(int i=0; i<(1<<3); i++) {
    ll a[1005]={};
    for(int j=0; j<n; j++) {
      a[j]=x[j]*(i&1?1:-1)+y[j]*(i&2?1:-1)+z[j]*(i&4?1:-1);
    }
    sort(a,a+n,greater<ll>());
    cnt=0;
    for(int j=0; j<m; j++) {
      cnt+=a[j];
    }
    ans=max(ans,cnt);
  }
  cout << ans << "\n";
}