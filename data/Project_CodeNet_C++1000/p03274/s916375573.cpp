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
  int n,k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i,n) cin >> x[i];

  int l = 0, r = k - 1;
  int ans = 1e9;
  while(r<n){
    int res;
    if(x[r]<=0) res = -x[l];
    if(0<=x[l]) res = x[r];
    if(x[l]<0 && 0<x[r]) res = x[r] - x[l] + min(-x[l],x[r]);
    ans = min(ans,res);
    ++l; ++r;
  }
  cout << ans << endl;
}
