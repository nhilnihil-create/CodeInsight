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
  int n,x;
  cin >> n >> x;
  int m = 1e9;
  rep(i,n){
    int mi;
    cin >> mi;
    x-=mi;
    m = min(m,mi);
  }
  int ans = n+x/m;
  cout << ans << endl;
}
