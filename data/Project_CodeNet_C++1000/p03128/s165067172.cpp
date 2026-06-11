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

int c[10] = {6,2,5,5,4,5,6,3,7,6};
vector<int> a;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  sort(a.rbegin(),a.rend());

  vector<int> dp(n+1,-1e9);
  dp[0] = 0;
  rep(mi,m){
    int d = a[mi];
    rep(i,n-c[d]+1){
      dp[i+c[d]] = max(dp[i+c[d]],dp[i]+1);
    }
  }
  vector<int> ans;
  while(n>0){
    rep(i,m){
      int d = a[i];
      while(n>=c[d] && dp[n]-1 == dp[n-c[d]]){
        ans.push_back(d);
        n -= c[d];
      } 
    }
  }
  sort(ans.rbegin(),ans.rend());
  rep(i,ans.size()) cout << ans[i]; cout << endl;
}