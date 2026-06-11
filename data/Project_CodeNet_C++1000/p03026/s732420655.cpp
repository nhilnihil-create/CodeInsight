#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int n;
const int max_n = 1e4+10;
queue<int> q;

int d[max_n];

vector<int> g[max_n];

void dfs(int i, int p){

  for(auto nv : g[i]){

    if(nv == p) continue;

    dfs(nv, i);

  }

  int now = q.front();
  q.pop();
  d[i] = now;

}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> c(n);
  rep(i, n) cin >> c[i];

  sort(c.begin(), c.end());

  ll ans = 0;
  rep(i, n-1){
    ans += c[i];
  }

  rep(i, n){
    q.push(c[i]);
  }

  int ind = -1;
  rep(i, n){
    if(g[i].size() >= 2){
      ind = i;
      break;
    }
  }

  dfs(ind, -1);

  cout << ans << endl;
  rep(i, n){
    cout << d[i] << " ";
  }
  cout << endl;

  
  
  return 0;
}
