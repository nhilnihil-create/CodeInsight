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
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,cnta=0,cntb=0,cntab=0,cnt=0;
  string s;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> s;
    if(s[0]=='B'&&s[s.size()-1]=='A') {
      cntab++;
    }
    else if(s[0]=='B') {
      cntb++;
    }
    else if(s[s.size()-1]=='A') {
      cnta++;
    }
    for(int j=0; j<s.size()-1; j++) {
      if(s[j]=='A'&&s[j+1]=='B') {
        cnt++;
      }
    }
  }
  if(cntab==0) {
    cout << cnt+min(cnta,cntb) << endl;
  }
  else if(cnta+cntb) {
    cout << cnt+cntab+min(cnta,cntb) << endl;
  }
  else {
    cout << cnt+cntab-1 << endl;
  }
}