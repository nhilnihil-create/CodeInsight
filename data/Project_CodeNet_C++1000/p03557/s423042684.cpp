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
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  vector<ll> v(n+1); int j;
  j=n;
  rep(i,n){
    while(j>0 && c[j-1]>b[n-1-i]) --j;
    v[n-1-i] = v[n-i] + n-j;
  }
  ll ans = 0;
  j=0;
  rep(i,n){
    while(j<n && b[j]<=a[i]) ++j;
    ans += v[j];
  }
  cout << ans << endl;
}
