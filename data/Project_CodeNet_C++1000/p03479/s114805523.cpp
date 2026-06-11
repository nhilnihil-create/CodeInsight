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
  ll x,y;
  cin >> x >> y;
  int ans = 0;
  while(x<=y){
    ++ans;
    x<<=1;
  }
  cout << ans << endl;
}
