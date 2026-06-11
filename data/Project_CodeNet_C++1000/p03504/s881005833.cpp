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

int MAX=100001;
int main() {
  int n,m;
  cin >> n >> m;
  
  vector<int> sb(MAX),tb(MAX);
  rep(i,n){
    int s,t,c;
    cin >> s >> t >> c;
    --c;
    sb[s] |= 1<<c;
    tb[t] |= 1<<c;
  }
  int ans = 1, x = 0;
  rep(i,MAX){
    x ^= sb[i];
    ans = max(ans,__builtin_popcount(x)-__builtin_popcount(sb[i]&tb[i]));
    x ^= tb[i];
  }
  cout << ans << endl;
}