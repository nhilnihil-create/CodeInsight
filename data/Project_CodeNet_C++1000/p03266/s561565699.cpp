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

  ll ans = 0;
  ll m = n/k;
  ans += m*m*m;
  if(k%2==0){
    m = n/(k/2) - m;
    ans += m*m*m;
  }
  cout << ans << endl;
}
