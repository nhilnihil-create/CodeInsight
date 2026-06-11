#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll n,m;
ll s[e5];
graph g;
ll a_cnt[e5];
ll b_cnt[e5];
ll vis[e5];
queue<ll> q;

int main(){
  cin >> n >> m;
  string s_;
  cin >> s_;
  for(ll i = 1;i <= n;i++){
    s[i] = (s_[i-1] == 'A' ? 0 : 1);
  }
  for(ll i = 0;i < m;i++){
    ll a,b;
    cin >> a >> b;
    g[a][b]++;
    g[b][a]++;
    if(s[a] == 0) a_cnt[b]++;
    else b_cnt[b]++;
    if(s[b] == 0) a_cnt[a]++;
    else b_cnt[a]++;
  }
  for(ll i = 1;i <= n;i++){
    if(a_cnt[i] == 0 || b_cnt[i] == 0){
      q.push(i);
      vis[i] = 1;
    }
  }
  // for(ll i = 1;i <= n;i++) cerr << a_cnt[i] << " ";
  // cerr << endl;
  // for(ll i = 1;i <= n;i++) cerr << b_cnt[i] << " ";
  // cerr << endl;
  ll k = n;
  while(!q.empty()){
    ll x = q.front();
    q.pop();
    for(auto y : g[x]){
      if(s[x] == 0) a_cnt[y.first] -= g[x][y.first];
      else b_cnt[y.first] -= g[x][y.first];
      if((a_cnt[y.first] == 0 || b_cnt[y.first] == 0) && vis[y.first] == 0){
        q.push(y.first);
        vis[y.first] = 1;
      }
    }
    k--;
  }
  // for(ll i = 1;i <= n;i++) cerr << a_cnt[i] << " ";
  // cerr << endl;
  // for(ll i = 1;i <= n;i++) cerr << b_cnt[i] << " ";
  // cerr << endl;
  if(k == 0) cout << "No" << endl;
  else cout << "Yes" << endl;


}
