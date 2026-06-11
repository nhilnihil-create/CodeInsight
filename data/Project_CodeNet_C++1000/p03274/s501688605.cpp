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
const ll INF=5e18;
using P=pair<int,int>;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,k,a[100005]={},ans=inf;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n-k+1; i++) {
    if(a[i+k-1]<=0) {
      ans=min(ans,abs(a[i]));
    }
    else if(a[i]>=0) {
      ans=min(ans,a[i+k-1]);
    }
    else {
      ans=min({ans,abs(a[i])*2+a[i+k-1],abs(a[i])+a[i+k-1]*2});
    }
  }
  cout << ans << endl;
}