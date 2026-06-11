#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;

  vector<ll> sum(n + 1);
  rep(i, n) {
    sum[i + 1] = sum[i] + a[i];
  }

  map<int, ll> count;
  rep(i, n + 1) {
    ++count[sum[i] % m];
  }

  for (auto it = count.begin(); it != count.end(); ++it) {
    ans += (it->second) * (it->second - 1) / 2;
  }
  cout << ans << endl;
}