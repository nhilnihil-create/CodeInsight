#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template <typename T> T id(T b) {return b;};
template <class It> bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It> bool any(It f,It l){return std::any_of(f,l,id<bool>);}
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}

const int MAX_N = 200000;
int n;
vi g[MAX_N];
int d[MAX_N];

void dfs(int u, int p, int lv) {
  d[u] = lv;

  for (int v : g[u]) {
    if (v != p) dfs(v,u,lv+1);
  }
}

int main()
{
#ifdef FASTIO
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif

  cin >> n;

  int a,b;
  forn1(i,n-1) {
    cin >> a >> b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0,-1,0);

  int u = max_element(d,d+n) - d;

  dfs(u,-1,0);

  int di = *max_element(d,d+n);

  // 余り1を強制できる方が勝ち
  if (di % 3 == 1)
    cout << "Second\n";
  else
    cout << "First\n";

  return 0;
}
