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
const int inf=1e9;
const ll INF=5e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,x[55]={},y[55]={},ans=INF,cnt=0;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<n; k++) {
        for(int l=0; l<n; l++) {
          if(x[i]<x[j]&&y[k]<y[l]) {
            cnt=0;
            for(int o=0; o<n; o++) {
              if(x[i]<=x[o]&&x[o]<=x[j]&&y[k]<=y[o]&&y[o]<=y[l]) {
                cnt++;
              }
            }
            if(cnt>=m) {
              ans=min(ans,(x[j]-x[i])*(y[l]-y[k]));
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}