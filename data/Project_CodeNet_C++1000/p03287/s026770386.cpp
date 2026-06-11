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
  map<int,ll> d;
  int s = 0;
  d[0]++;
  rep(i,n) {
    int a;
    cin >> a;
    s = (s+a)%m;
    d[s]++;
  }
  ll ans = 0;
  for(auto i:d) ans += i.second*(i.second-1)/2;
  cout << ans << endl;
}