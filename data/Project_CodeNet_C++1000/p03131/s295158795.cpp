#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  // 最初にmin(a, k)枚分叩いておく
  ++k;
  ll ans = min(a, k);
  k -= a;
  ll diff = b - a;
  if (diff >= 2 && k >= 0) {
    ans += (diff) * (k / 2) + k % 2;
  } else {
    ans += max(0, k);
  }

  cout << ans << endl;
}