#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll sum = 0;
  map<ll, ll> cnt;
  ll ans = 0;
  cnt[0]++;
  rep(i, n) {
    sum += a[i];
    ans += cnt[sum];
    cnt[sum]++;
  }
  cout << ans << endl;

}