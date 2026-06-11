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
  int a,b,k,f=1;
  cin >> a >> b >> k;
  while(k) {
    if(f) {
      f=0;
      if(a%2) {
        a--;
        a/=2;
        b+=a;
      }
      else {
        a/=2;
        b+=a;
      }
    }
    else {
      f=1;
      if(b%2) {
        b--;
        b/=2;
        a+=b;
      }
      else {
        b/=2;
        a+=b;
      }
    }
    k--;
  }
  cout << a << " " << b << endl;
}
