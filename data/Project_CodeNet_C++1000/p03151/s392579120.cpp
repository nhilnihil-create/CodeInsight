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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll cost = 0;
  int ans = 0;

  rep(i, n) {
    if (a[i] < b[i]) {
      cost -= a[i] - b[i];
      ans++;
    }
    
  }

  vector<int> stock;
  rep(i, n) if (a[i] > b[i]) stock.push_back(a[i] - b[i]);

  int m = stock.size();
  sort(stock.rbegin(), stock.rend());
  // cout << cost << endl;

  rep(i, m) {
    if (cost <= 0) break;
    cost -= stock[i];
    ans++;
  }
  if (cost > 0) ans = -1;

  cout << ans << endl;

}