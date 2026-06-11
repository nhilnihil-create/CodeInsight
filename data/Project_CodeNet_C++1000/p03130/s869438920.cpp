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
  int a,b,ans[4]={};
  for(int i=0; i<3; i++) {
    cin >> a >> b;
    a--,b--;
    ans[a]++,ans[b]++;
  }
  cout << (ans[0]<3&&ans[1]<3&&ans[2]<3&&ans[3]<3?"YES":"NO") << endl;
}
