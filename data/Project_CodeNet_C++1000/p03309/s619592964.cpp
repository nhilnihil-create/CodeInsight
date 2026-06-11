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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    a[i] -= i+1;
  }
  sort(a.begin(),a.end());
  auto f = [&](ll b){
    ll res = 0;
    rep(i,n) res += abs(a[i]-b);
    return res;
  };
  ll ans;
  if(n%2==0){
    ans = min(f(a[n/2-1]),f(a[n/2]));
  }else{
    ans = f(a[n/2]);
  }
  cout << ans << endl;
}
