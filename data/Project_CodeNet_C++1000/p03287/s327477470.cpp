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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  vector<ll> b(n+1, 0);
  map<ll, ll> mp;
  mp[0]++;
  REP(i, n){
    b[i+1] = (a[i]+b[i])%m;
    mp[b[i+1]]++;
  }
  ll ans = 0;
  for(auto p : mp){
    ans += p.second*(p.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}