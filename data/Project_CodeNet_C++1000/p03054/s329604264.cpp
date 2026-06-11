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
  int h,w,n,sr,sc,a,b,c,d;
  cin >> h >> w >> n >> sr >> sc;
  string s,t;
  cin >> s >> t;
  a=sc,b=sc,c=sr,d=sr;
  for(int i=0; i<n; i++) {
    if(s[i]=='L') {
      b--;
    }
    if(s[i]=='R') {
      a++;
    }
    if(s[i]=='U') {
      c--;
    }
    if(s[i]=='D') {
      d++;
    }
    if(b<1||a>w||c<1||d>h) {
      cout << "NO" << endl;
      return 0;
    }
    if(t[i]=='L') {
      a=max(1,a-1);
    }
    if(t[i]=='R') {
      b=min(w,b+1);
    }
    if(t[i]=='U') {
      d=max(1,d-1);
    }
    if(t[i]=='D') {
      c=min(h,c+1);
    }
  }
  cout << "YES" << endl;
}