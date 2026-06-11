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
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;

int n, a, b, c;
vector<int> l;
int dfs(int d, int la, int lb, int lc) {
  if(d == n) {
    if(la == 0 || lb == 0 || lc == 0) return INF; 
    return abs(la - a) + abs(lb - b) + abs(lc - c) - 30;
  }
  int res = INF;
  chmin(res, dfs(d + 1, la, lb, lc));
  chmin(res, dfs(d + 1, la + l[d], lb, lc) + 10);
  chmin(res, dfs(d + 1, la, lb + l[d], lc) + 10);
  chmin(res, dfs(d + 1, la, lb, lc + l[d]) + 10);
  return res;
}

int main() {
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i, n) {
    cin >> l[i];
  }
  int ans = dfs(0, 0, 0, 0);
  cout << ans << endl;

}