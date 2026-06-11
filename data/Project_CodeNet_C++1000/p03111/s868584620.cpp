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
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<int> l(n);
  rep(i,n) cin >> l[i];

  int m = (1<<n)-1;
  vector<pair<ll,ll>> ls(m);
  ls[0].first = 1e9;
  rep(x,m){
    rep(i,n){
      if((x&(1<<i))>0){
        ls[x].first += l[i];
        ls[x].second++;
      }
    }
  }
  ll ans = 1e9;
  rep(i,m){
    if(ls[i].second>a) continue;
    rep(j,m){
    if((i&j)>0) continue;
    if(ls[j].second>b) continue;
      rep(k,m){
        if((i&k)>0 || (j&k)>0) continue;
        if(ls[k].second>c) continue;
        ll temp = abs(ls[i].first-a) + 10*(ls[i].second-1)
                + abs(ls[j].first-b) + 10*(ls[j].second-1)
                + abs(ls[k].first-c) + 10*(ls[k].second-1);
        ans = min(ans,temp);
      }
    }
  }
  cout << ans << endl;
}
