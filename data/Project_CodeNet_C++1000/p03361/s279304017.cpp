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

int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  auto ok = [&](int i,int j){
    return 0<=i&&i<h&&0<=j&&j<w&&s[i][j]=='#';
  };
  bool ans = true;
  rep(i,h)rep(j,w){
    if(s[i][j]=='.')continue;
    ans &= [&]{
      bool res = false;
      rep(d,4) res |= ok(i+x[d],j+y[d]);
      return res;
    }();
  }
  cout << (ans?"Yes":"No") << endl;
}
