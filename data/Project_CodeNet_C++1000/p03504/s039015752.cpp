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
  int n,cc,ans=0,s[200005]={},t[200005]={},c[200005]={},cnt[200005]={};
  cin >> n >> cc;
  for(int i=0; i<n; i++) {
    cin >> s[i] >> t[i] >> c[i];
  }
  for(int i=1; i<=cc; i++) {
    int tt[200005]={};
    for(int j=0; j<n; j++) {
      if(c[j]==i) {
        tt[s[j]*2-1]++,tt[t[j]*2]--;
      }
    }
    for(int j=1; j<200005; j++) {
      tt[j]+=tt[j-1];
    }
    for(int j=0; j<200005; j++) {
      if(tt[j]) {
        cnt[j]++;
      }
    }
  }
  for(int i=0; i<200005; i++) {
    ans=max(ans,cnt[i]);
  }
  cout << ans << endl;
}