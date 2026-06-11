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
  int n,a,ans=1,cnt=1;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a;
    ans*=3;
    if(a%2==0) {
      cnt*=2;
    }
  }
  cout << ans-cnt << endl;
}