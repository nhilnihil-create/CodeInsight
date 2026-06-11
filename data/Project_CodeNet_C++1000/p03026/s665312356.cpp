#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
}*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1LL<<60;

int n;
vi es[101010];
vi c;
int ans[101010];
int cnt;

void dfs(int v, int p = -1){
  ans[v] = c[cnt];
  cnt++;
  for(int to : es[v]) if(to != p){
    dfs(to, v);
  }
}

signed main() {
  cin >> n;
  rep(i, 0, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    es[a].emplace_back(b);
    es[b].emplace_back(a);
  }
  c.resize(n);
  rep(i, 0, n) cin >> c[i];

  sort(c.rbegin(), c.rend());
  cnt = 0;
  dfs(0);

  int sum = 0;
  rep(i, 1, n) sum += c[i];

  cout << sum << endl;
  rep(i, 0, n) cout << ans[i] << " \n"[i==n-1];

  return 0;
}

