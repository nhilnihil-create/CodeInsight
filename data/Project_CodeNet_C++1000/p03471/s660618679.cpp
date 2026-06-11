// Q from "https://atcoder.jp/contests/abc085/tasks/abc085_c"

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int n, y;
  cin >> n >> y;
  rep(i, n+1) {
    rep(j, n+1) {
      if (i + j <= n && 10000 * i + 5000 * j + (1000 * (n - i - j)) == y) {
        cout << i << " " << j << " " << n - i - j;
        return;
      }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;
}

int main() {
  solve();
  return 0;
}