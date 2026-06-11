#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define fi first
#define se second
#define DEBUG(x) cerr << (#x) << ": " << (x) << '\n'
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
 
template<class T> bool uin(T &a, T b) {return (a < b ? false : (a = b, true));}
template<class T> bool uax(T &a, T b) {return (a > b ? false : (a = b, true));}
 
//~ ifstream f(".in");
//~ ofstream g(".out");
 
struct Block {
  int w, s, v;
};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL_DEFINE
  freopen(".in", "r", stdin);
#endif
 
  int n;
  cin >> n;
  int max_s = 0;
  vector<Block> blocks(n + 2);
  for (int i = 1; i <= n; ++i) {
    int w, s, v;
    uax(max_s, s);
    cin >> w >> s >> v;
    blocks[i] = {w, s, v};
  }
  sort(blocks.begin() + 1, blocks.begin() + n + 1,
    [&](const Block &a, const Block &b) {
      return a.w + a.s < b.w + b.s;
  });
  
  ll ans = 0;
  vector<ll> dp(20005);
  for (int i = 1; i <= n; ++i) {
    for (int w = blocks[i].s; w >= 0; --w) {
      uax(dp[w + blocks[i].w], dp[w] + blocks[i].v);
    }
  }
  for (int i = 0; i <= (int)2e4 + 1; ++i) {
    uax(ans, dp[i]);
  }
  
  cout << ans << '\n';
 
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
