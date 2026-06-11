#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

signed main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  int b = n%2 ? a[n/2] : (a[n/2] + a[n/2-1]) / 2;
  ll ans = 0;
  rep(i,n) ans += abs(a[i] -b);
  cout << ans << endl;
}
