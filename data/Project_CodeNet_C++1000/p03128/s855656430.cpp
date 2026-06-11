#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main(void){
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  REP(i, m) cin >> a[i];
  int num[] = {INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  sort(ALLr(a));
  vector<int> dp(n+1, -INF);
  dp[0] = 0;
  FORe(i, 1, n){
    REP(j, m){
      if(i - num[a[j]] < 0) continue;
      chmax(dp[i], dp[i-num[a[j]]]+1);
    }
  }
  string ans;
  int l = dp[n];
  REP(i, l){
    REP(j, m){
      if(n - num[a[j]] < 0) continue;
      if(dp[n-num[a[j]]] == dp[n]-1){
        ans += (char)a[j] + '0';
        n -= num[a[j]];
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}