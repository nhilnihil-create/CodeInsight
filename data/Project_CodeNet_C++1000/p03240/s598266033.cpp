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
  int n;
  cin >> n;
  vector<pair<int,P>> v(n);
  rep(i,n){
    int x,y,h;
    cin >> x >> y >> h;
    v[i] = make_pair(h,P(x,y));
  }
  sort(v.begin(),v.end());
  auto f = [&](int i,int cx,int cy){
    int x = v[i].second.first, y = v[i].second.second, h = v[i].first;
    return h+abs(x-cx)+abs(y-cy);
  };
  rep(cx,101)rep(cy,101){
    bool ok = true;
    int ch = f(n-1,cx,cy);
    rep(i,n-1){
      int h = f(i,cx,cy);
      if(ch==h) continue;
      else if(h>ch && v[i].first==0) continue;
      ok = false;
      break;
    }
    if(ok){
      printf("%d %d %d\n",cx,cy,ch);
      return 0;
    }
  }
}
