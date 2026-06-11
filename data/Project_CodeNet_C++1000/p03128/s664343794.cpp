#include <bits/stdc++.h>
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define ALL(obj) (obj).begin(), (obj).end()
#define fi first
#define se second
#define NIL -1
using ll = long long;
const ll MOD = 1000000007;
#define REP(i,n) for (ll i=0; i < (n); ++i)
#define FOR(i,a,b) for (ll i=(a); i < (b); ++i)
using namespace std;

int get_gcd(int a, int b){while(1){if (a < b) swap(a, b); if (b == 0) return a; a %= b;}}
int get_lcm(int a, int b){return a * b / get_gcd(a, b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

signed main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  array<int, 10> num = {0,2,5,5,4,5,6,3,7,6};

  int m,n;
  cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  sort(ALL(a), greater<int>());

  //dp[i] ... ちょうどi本のマッチ棒を使って作れる整数の最大桁数
  //まずはdp[i]を求める。
  vector<int> dp(n+1);
  dp[0] = 0;
  for (int i=1; i<=n; i++) {
    int max_ = MIN;
    REP(j,m) {
      // A[j]を使ったときの残りのマッチの本数
      int r = i - num[a[j]];
      if (r < 0) continue;
      max_ = max(max_, dp[r] + 1);
    }
    dp[i] = max_;
  }

  //dp[n]について、具体的な整数を決定していく。
  int ans = 0;
  int r = n; // 残りのマッチの本数
  REP(i,n) {
    // A[j]が使えるかを見る。使えたらそれに決定。
    int j = 0;
    REP(j,m) {
      if (r-num[a[j]] < 0) continue;
      if (dp[r - num[a[j]]] == dp[r] - 1) {
        cout << a[j];
        r -= num[a[j]];
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
