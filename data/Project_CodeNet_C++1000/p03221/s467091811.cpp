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
  vector<vector<P>> v(n);
  rep(i,m){
    int p,y;
    cin >> p >> y;
    --p;
    v[p].emplace_back(y,i);
  }
  vector<P> ans(m);
  rep(i,n){
    sort(v[i].begin(),v[i].end());
    int x = 0;
    for(P p:v[i]){
      ans[p.second].first = i+1;
      ans[p.second].second = ++x;
    }
  }
  rep(i,m) printf("%06d%06d\n",ans[i].first,ans[i].second);
}
