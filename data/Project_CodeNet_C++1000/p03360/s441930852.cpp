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
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int ans = max({a,b,c});
  int n = a+b+c - ans;
  ans <<= k;
  ans += n;
  cout << ans << endl;
}
