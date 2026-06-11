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
const ll INF=5e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,d,a,posx[90005]={},posy[90005]={},x[90005]={},q,l,r;
  cin >> h >> w >> d;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> a;
      posx[a]=j,posy[a]=i;
    }
  }
  for(int i=d+1; i<=h*w; i++) {
    x[i]=x[i-d]+abs(posx[i]-posx[i-d])+abs(posy[i]-posy[i-d]);
  }
  cin >> q;
  while(q--) {
    cin >> l >> r;
    cout << x[r]-x[l] << endl;
  }
}