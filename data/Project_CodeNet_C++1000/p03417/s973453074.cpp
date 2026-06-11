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
  if(n == 1 && m == 1){
    cout << 1 << endl;
    return 0;
  }

  //外周以外のマスは9回参照される->裏
  ll ans = max(0ll, n-2) * max(0ll, m-2);
  //角:4 or 2 ->表;
  //辺:6 or 3
  if(n == 1 || m == 1){
    ans += max(n-2, m-2);
  }
  cout << ans << endl;
  return 0;
}