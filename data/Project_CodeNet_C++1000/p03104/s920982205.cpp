#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

ll f(ll x) {
  ll res = 0;
  ll loop = 2;
  x++;
  rep(i, 41) {
    ll remaincnt = max(0LL, x % loop - loop / 2);
    ll sumcnt = x / loop * (loop / 2);
    ll cnt = sumcnt + remaincnt;

    if (cnt % 2) res += 1LL << i;
    loop *= 2;
  }

  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  a--;
  if (a < 0) a = 0;
  ll ans = f(b) ^ f(a);
  // cout << f(a) << " " << f(b) << endl;
  cout << ans << endl;
}