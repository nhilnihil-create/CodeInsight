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
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=9e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,c[100005]={},s[200005]={},t[200005]={},x[200005]={},cnt[200005]={},ans=0,ch;
  cin >> n >> ch;
  for(int i=0; i<n; i++) {
    cin >> s[i] >> t[i] >> c[i];
  }
  for(int i=1; i<=ch; i++) {
    int time[200005]={};
    for(int j=0; j<n; j++) {
      if(c[j]==i) {
        time[s[j]*2-1]++,time[t[j]*2]--;
      }
    }
    for(int j=1; j<200005; j++) {
      time[j]+=time[j-1];
    }
    for(int j=0; j<200005; j++) {
      if(time[j]) {
        cnt[j]++;
      }
    }
  }
  for(int i=0; i<200005; i++) {
    ans=max(ans,cnt[i]);
  }
  cout << ans << endl;
}