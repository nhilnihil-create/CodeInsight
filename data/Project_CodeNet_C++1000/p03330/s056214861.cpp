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

  int N,C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  vector<vector<int>> c(N, vector<int>(N));
  vector<vector<int>> cell(3);
  repr(i, C, 0) {
    repr(j, C, 0) {
      cin >> D[i][j];
    }
  }
  repr(i, N, 0) {
    repr(j, N, 0) {
      int x=j+1,y=i+1;
      cin >> c[i][j];
      c[i][j]--;
      cell[(x+y)%3].push_back(c[i][j]);
    }
  }
  vector<vector<int>> cost(3, vector<int>(C,0));

  for (int i = 0; i < C; ++i) {
    for (auto itr : cell[0]) { cost[0][i] += D[itr][i]; }
    for (auto itr : cell[1]) { cost[1][i] += D[itr][i]; }
    for (auto itr : cell[2]) { cost[2][i] += D[itr][i]; }
  }

  int ans = numeric_limits<int>::max();
  // 塗り替える色を全探索
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < C; ++j) {
      if (i == j) continue;
      for (int k = 0; k < C; ++k) {
        int temp = 0;
        if (i == k || j == k) continue;
        temp += cost[0][i];
        temp += cost[1][j];
        temp += cost[2][k];

        chmin(ans, temp);
      }
    }
  }

  cout << ans << endl;
}