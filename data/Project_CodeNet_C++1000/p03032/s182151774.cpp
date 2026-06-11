#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, k;
int v[50];

signed main() {
  cin >> n >> k;
  rep(i,n) cin >> v[i];

  int ans = 0;

  for (int a=0; a<=min(n,k); a++ ) 
    for(int b=0; b<=min(n,k) - a; b++)
    {
      multiset<int> s;
      int sum = 0;
      for(int i=0; i<a; i++) {
        sum += v[i];
        s.insert(v[i]);
      }
      for(int i=n-1; i>=n-b; i--) {
        sum += v[i];
        s.insert(v[i]);
      }
      int cd=min(a+b, k-a-b);
      rep(i, cd) {
        int m = *s.begin();
        if (m>=0) break;
        sum -= m;
        s.erase(m);
      }
      ans = max(ans ,sum);
    }
  cout << ans << endl;
}
