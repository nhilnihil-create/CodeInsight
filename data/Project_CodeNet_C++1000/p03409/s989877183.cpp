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
  vector<P> a(n),b(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  rep(i,n) cin >> b[i].first >> b[i].second;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ans = 0;
  vector<bool> used(n);
  rep(i,n){
    int idx = -1, y = -1;
    rep(j,n){
      if(a[j].first>=b[i].first) break;
      if(used[j]) continue;
      if(a[j].second>=b[i].second) continue;
      if(y<a[j].second){
        idx = j;
        y = a[j].second;
      }
    }
    if(idx!=-1){
      ++ans;
      used[idx] = true;
    }
  }
  cout << ans << endl;
}
