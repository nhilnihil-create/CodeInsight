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
  int n,m;
  cin >> n >> m;
  vector<P> v(m);
  rep(i,m) cin >> v[i].first >> v[i].second;
  sort(v.begin(),v.end());

  int ans = 1;
  P p = v[0];
  rep(i,m){
    if(p.second<=v[i].first){
      ++ans;
      p = v[i];
    }else{
      p.first = max(p.first,v[i].first);
      p.second = min(p.second,v[i].second);
    }
  }
  cout << ans << endl;
}