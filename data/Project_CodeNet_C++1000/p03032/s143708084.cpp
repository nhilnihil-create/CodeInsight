#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  int c = min(n,m)+1;
  ll ans = -10000000000;
  for(int i = 0; i < c; i++) {
    for(int j = 0; j < c-i; j++) {
      //printf("i = %d, j = %d start!\n",i,j);
      vector<ll> a(0);
      for(int k = 0; k < i; k++) {
        a.push_back(v[k]);
      }
      for(int k = 0; k < j; k++) {
        a.push_back(v[n-1-k]);
      }
      sort(a.begin(),a.end());
      ll value = 0;
      for(int k = 0; k < i+j; k++) {
        //printf("%lld ", a[k]);
        if (k < m-i-j && a[k] < 0) continue;
        value += a[k];
      }
      //printf("\n");
      ans = max(ans,value);
    }
  }
  cout << ans << endl;
  return 0;
}
