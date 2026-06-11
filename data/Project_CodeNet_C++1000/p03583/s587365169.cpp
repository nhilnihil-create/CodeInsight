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
  ll N;
  cin >> N;
  for(ll i=1; i<=3500; i++) {
    for(ll j=1; j<=3500; j++) {
      ll x=N*i*j,y=4*i*j-N*i-N*j;
      if(x>0&&y>0&&x%y==0) {
        cout << i << " " << j << " " << x/y << endl;
        return 0;
      }
    }
  }
}