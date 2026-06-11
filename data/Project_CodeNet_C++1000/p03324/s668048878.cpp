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
  int d,n;
  cin >> d >> n;
  int ans = n;
  rep(i,d) ans *= 100;
  if(n==100) {
    n = 1;
    rep(i,d) n *= 100;
    ans += n;
  } 
  cout << ans << endl;
}
