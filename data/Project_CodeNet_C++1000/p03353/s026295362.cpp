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
  string s;
  int k,l,x;
  cin >> s >> k;
  set<string> se;
  l=s.size(),x=k;
  k=min(k,l);
  while(k) {
    for(int i=0; i<s.size()-k+1; i++) {
      se.insert(s.substr(i,k));
    }
    k--;
  }
  auto itr=se.begin();
  for(int i=0; i<x-1; i++) {
    itr++;
  }
  cout << *itr << endl;
}