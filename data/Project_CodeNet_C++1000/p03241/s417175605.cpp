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

  int ans = 1;
  auto f = [&](int i){ if(m/i>=n) ans = max(ans,i); };
  for(int i=1;i*i<=m;++i) {
    if(m%i==0) {
      f(i); f(m/i);
    }
  }
  cout << ans << endl;
}