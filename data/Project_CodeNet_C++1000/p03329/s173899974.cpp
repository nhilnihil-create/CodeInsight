#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> dp(n+1000);
  repr(i, n+10, 0) {
    dp[i] = i;
  }

  for (int i = 0; i <= n; ++i) {
    for (int six = 1; i + six <= n; six*=6) {
      dp[i+six] = min(dp[i+six], dp[i] + 1);
    }

    for (int nine = 1; i + nine <= n; nine*=9) {
      dp[i+nine] = min(dp[i+nine], dp[i] + 1);
    }
  }

  cout << dp[n] << endl;
}