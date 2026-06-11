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
const int inf=1e9;
const ll INF=1e18;
const double pi=3.1415926535897932384626433832;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,ans=inf,w[200005]={},b[200005]={};
  string s;
  cin >> n >> s;
  for(int i=1; i<=n; i++) {
    if(s[i-1]=='#') {
      b[i]=b[i-1]+1;
    }
    else {
      b[i]=b[i-1];
    }
  }
  for(int i=1; i<=n; i++) {
    if(s[i-1]=='.') {
      w[i]=w[i-1]+1;
    }
    else {
      w[i]=w[i-1];
    }
  }
  for(int i=1; i<=n; i++) {
    ans=min(ans,b[i-1]+w[n]-w[i]);
  }
  cout << ans << endl;
}