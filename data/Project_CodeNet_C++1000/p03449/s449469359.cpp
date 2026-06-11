#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int N;
  cin >> N;
  vector A(2, vector<int>(N));
  rep(i,2) rep(j,N) cin >> A[i][j];

  int ans = 0;
  rep(i,N) {
    int count = 0;
    rep(j,N) {
      if (j <= i) count += A[0][j];
      if (i <= j) count += A[1][j];
    }
    ans = max(ans, count);
  }

  cout << ans << endl;

  return 0;
}