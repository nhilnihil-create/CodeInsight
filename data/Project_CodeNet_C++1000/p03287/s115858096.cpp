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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> sum(n + 1);
  rep(i, n) sum[i + 1] = (sum[i] + a[i])% m;
  
  map<ll, ll> cnt;
  rep(i, n) cnt[sum[i + 1]]++;
  cnt[0]++;
  ll ans = 0;
  for(auto c : cnt) {
    ans += c.second * (c.second - 1) / 2;
  }
  cout << ans << endl;
}
