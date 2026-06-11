#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

vvi G;
vi color;

bool dfs(int v, int col = 1){
  color[v] = col;
  for(auto nv : G[v]){
    if(color[nv] != -1){
      if(color[nv] == col) return false;
    }
    else{
      if(!dfs(nv, 1-col)) return false;
    }
  }
  return true;
}

int main(){
  ll n; int m;
  cin >> n >> m;
  G.resize(n);
  rep(i, m){
    int a,b; cin >> a >> b;
    a--; b--;
    G[a].pb(b); G[b].pb(a);
  }

  color.resize(n, -1);
  bool biparticle;
  biparticle = dfs(0);
  ll ans;
  if(biparticle){
    ll cnt = 0;
    rep(i, n) cnt += color[i];
    ans = cnt*(n-cnt) - m;
  }
  else{
    ans = n*(n-1)/2 - m;
  }

  std::cout << ans << '\n';
}
