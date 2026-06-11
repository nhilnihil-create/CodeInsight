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
using P = pair<ll, ll>;
const int INF = 1001001001;

int main(void){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll mn = INF, mx = -INF, mnidx, mxidx;
  REP(i, n){
    cin >> a[i];
    if(a[i] < mn){
      mn = a[i];
      mnidx = i;
    }
    if(mx < a[i]){
      mx = a[i];
      mxidx = i;
    }
  }
  vector<P> ans;
  if(mn*mx < 0){
    if(mx >= labs(mn)){
      REP(i, n){
        a[i] += mx;
        ans.emplace_back(P(mxidx+1, i+1));
      }
      REP(i, n-1){
        a[i+1] += a[i];
        ans.emplace_back(P(i+1, i+2));
      }
    }else{
      REP(i, n){
        a[i] += mn;
        ans.emplace_back(P(mnidx+1, i+1));
      }
      REPr(i, n-1){
        a[i] += a[i+1];
        ans.emplace_back(P(i+2, i+1));
      }
    }
  }else{
    if(mn >= 0){
      REP(i, n-1){
        a[i+1] += a[i];
        ans.emplace_back(P(i+1, i+2));
      }
    }else{
      REPr(i, n-1){
        a[i] += a[i+1];
        ans.emplace_back(P(i+2, i+1));
      }
    }
  }
  ll m = ans.size();
  cout << m << endl;
  REP(i, m) cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}