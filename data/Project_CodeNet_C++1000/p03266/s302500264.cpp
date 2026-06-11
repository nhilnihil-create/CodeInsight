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
  ll n, k;
  cin >> n >> k;
  vector<ll> num(k, 0);
  FORe(i, 1, n) num[i%k]++;
  ll ans = 0;
  REP(a, k){
    ll b = (k-a)%k;
    ll c = (k-a)%k;
    if((b+c)%k != 0) continue;
    ans += num[a]*num[b]*num[c];
  }
  cout << ans << endl;
  return 0;
}