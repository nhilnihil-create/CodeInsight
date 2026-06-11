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
const int inf=1e9+5;
const ll INF=1e18+5;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int h,w,q,x[90005]={},posx[90005]={},posy[90005]={},d,a[305][305]={},l,r;
  cin >> h >> w >> d;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> a[i][j];
      posy[a[i][j]]=i,posx[a[i][j]]=j;
    }
  }
  for(int i=d+1; i<=h*w; i++) {
    x[i]=x[i-d]+abs(posy[i]-posy[i-d])+abs(posx[i]-posx[i-d]);
  }
  cin >> q;
  while(q--) {
    cin >> l >> r;
    cout << x[r]-x[l] << "\n";
  }
}