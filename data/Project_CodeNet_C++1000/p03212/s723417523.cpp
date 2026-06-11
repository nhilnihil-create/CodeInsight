#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<29;

const int MAX = 510000; //nCrのr
//const ll INF = (ll)1e18 + 1;

ll ans;
ll N;

void dfs(ll val, ll a, ll b, ll c){
  if (val > N) return;
  if (a & b & c) ans++;

  dfs(10 * val + 7, 1, b, c);
  dfs(10 * val + 5, a, 1, c);
  dfs(10 * val + 3, a, b, 1);
}

int main(){
  cin >> N;
  dfs(0, 0, 0, 0);
  cout << ans << endl;
}
