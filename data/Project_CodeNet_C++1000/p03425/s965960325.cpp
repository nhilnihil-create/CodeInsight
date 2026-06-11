#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

map<char,int> c = {
  {'M',0},
  {'A',1},
  {'R',2},
  {'C',3},
  {'H',4},
};
int main() {
  int n;
  cin >> n;
  vector<ll> m(5);
  rep(i,n){
    string s;
    cin >> s;
    if(c.count(s[0])==0) continue;
    m[c[s[0]]]++;
  }
  ll ans = 0;
  rep(i,5)rep(j,5)rep(k,5){
    if(i<j&&j<k) ans += m[i]*m[j]*m[k];
  }
  cout << ans << endl;
}
