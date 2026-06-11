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
#define rep(i,n) for(ll i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a,b;
  cin >> a >> b;

  auto f = [](ll x){
    ll res = 0;
    rep(i,(x+1)%4) res ^= x-i;
    return res;
  };
  cout << (f(a-1)^f(b)) << endl;
}