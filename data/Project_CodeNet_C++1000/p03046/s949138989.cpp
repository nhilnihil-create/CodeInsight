#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define all(x)        (x).begin(),(x).end()
#define eb            emplace_back
#define mp            make_pair
#define pb            push_back
#define fi            first
#define se            second
#define sz(x)         ((int)(x).size())
#define rep(x,y,z)    for(int x=y;x<z;x++)
#define per(x,z,y)    for(int x=z-1;x>=y;x--)
#define trav(y,x)     for(auto& y:x)
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define vi            vector<int>
#define vpi           vector<pii>

int dbg = 0;
#define cri           if(0)
#define shame         cri cerr<<(++dbg)<<"\n\n";

// aaaaaaaaaaaaaaaa
void solve() {
  int M, K, N;
  scanf("%d%d", &M, &K);
  N = (1 << M);
  if (N <= K || (M == 1 && K == 1)) {
    puts("-1");
    return;
  }
  if (!K) {
    rep(i, 0, N)
      printf("%d %d ", i, i);
    puts("");
    return;
  }

  vpi xork;
  vector<bool> mk(N, 0);
  mk[K] = 1;
  rep(i, 1, N) if (!mk[i]) {
    int j = i ^ K;
    xork.eb(i, j);
    mk[i] = 1;
    mk[j] = 1;
  }

  vi ans;
  ans.pb(0);
  int SZ = sz(xork);
  rep(i, 0, SZ) {
    ans.pb(xork[i].fi);
    ans.pb(xork[i].se);
  }
  ans.pb(0);
  ans.pb(K);
  per(i, SZ, 0) {
    ans.pb(xork[i].se);
    ans.pb(xork[i].fi);
  }
  ans.pb(K);

  trav(a, ans)
    printf("%d ", a);
  puts("");
}

int main() {
  // int _; scanf("%d", &_); while (_--)
  solve();
	return 0;
}

