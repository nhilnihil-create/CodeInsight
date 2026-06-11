#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];

  ll sum = 0;
  ll r = 0, ans = 0;
  REP(l, n){
    while(r < n && (sum^a[r]) == (sum+a[r])){
      sum += a[r++];
    }
    ans += r-l;
    if(l == r) r++;
    else sum -= a[l];
  }
  cout << ans << endl;
  return 0;
}