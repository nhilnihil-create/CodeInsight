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

bool f[100][10];
int p[100][11];
int main() {
  int n;
  cin >> n;
  rep(i,n)rep(j,10) cin >> f[i][j];
  rep(i,n)rep(j,11) cin >> p[i][j];
  int ans = -1e9;
  rep(b,1<<10){
    if(b==0) continue;
    int s = 0;
    rep(i,n){
      int c = 0;
      rep(j,10) if(b>>j&1 && f[i][j]) ++c;
      s += p[i][c];
    }
    ans = max(ans,s);
  }
  cout << ans << endl;
}
