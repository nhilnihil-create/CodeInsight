#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;


int main() {
  int n, C;
  cin >> n >> C;
  vector<vector<int>> d(C, vector<int>(C));
  vector<vector<int>> c(n, vector<int>(n));
  rep(i, C) rep(j, C) {
    cin >> d[i][j];
  }
  vector<vector<int>> cnt(3, vector<int>(C));
  rep(i, n) rep(j, n) {
    int t;
    cin >> t;
    --t;
    c[i][j] = t;
    int s = (i + j) % 3;
    cnt[s][t]++;
  }

  int ans = INF;
  rep(i, C)rep(j, C)if(i != j)rep(k, C) {
    if(j == k || k == i) continue;
    int t = 0;
    rep(x, 3) rep(y, C) {
      int next;
      if(x == 0) next = i;
      else if (x == 1) next = j;
      else next = k;
      t += cnt[x][y] * d[y][next];
    }
    ans = min(ans, t);
  }
  cout << ans << endl;
}
