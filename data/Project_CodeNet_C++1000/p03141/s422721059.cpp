#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll ans = 0;
  vector<ll> d(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
    d[i] = a[i] + b[i];
    ans += a[i];
  }
  
  sort(d.rbegin(), d.rend());
  for(int i = 1; i < n; i += 2) {
    ans -= d[i];
  }
  cout << ans << endl;

}