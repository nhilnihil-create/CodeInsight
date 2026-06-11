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

int main() {
  int n,t;
  cin >> n >> t;
  int ans = 1e9;
  rep(i,n){
    int c,ti;
    cin >> c >> ti;
    if(ti<=t) ans = min(ans,c);
  }
  if(ans>100000) cout << "TLE" << endl;
  else cout << ans << endl;
}
