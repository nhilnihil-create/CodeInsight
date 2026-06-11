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
  ll n,m;
  cin >> n >> m;
  ll ans = [&]{
    if(n==1&&m==1) return 1LL;
    if(n==1||m==1) return max(n,m)-2;
    return (n-2)*(m-2);
  }();
  cout << ans << endl;
}
