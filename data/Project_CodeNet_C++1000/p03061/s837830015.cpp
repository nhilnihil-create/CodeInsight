#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, a[100000];
int l[100000];
int r[100000];

signed main() {
  cin >> n;
  rep(i,n) cin >> a[i];

  l[0] = a[0];
  r[n-1] = a[n-1];

  for(int i=1;   i<n;  i++) l[i] = gcd(a[i], l[i-1]);
  for(int i=n-2; i>=0; i--) r[i] = gcd(a[i], r[i+1]);

  int ans = 0;
  rep(i,n) {
    int g;
    if(i==0) g = r[1];
    else if(i==n-1) g = l[n-2];
    else g = gcd(l[i-1], r[i+1]); 
    ans = max(ans,g);
  }
  cout << ans << endl;
}
