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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll ans = 0;
  int d=0,l=0,r=0;
  while(l<n){
    while( r<n && (d^a[r])==(d+a[r]) ) d ^= a[r++];
    ans += ll(r-l);
    d ^= a[l++];
  }
  cout << ans << endl;
}