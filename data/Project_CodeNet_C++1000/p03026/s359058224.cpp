#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 1e5 + 5;

int N, deg[maxn], c[maxn], d[maxn];
vector<int> adj[maxn];
priority_queue<ii, vector<ii>, greater<ii>> pq;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N;
  for(int i = 1; i < N; ++i){
    int u, v; cin >> u >> v;
    adj[u].eb(v); adj[v].eb(u);
    deg[u]++; deg[v]++;
  }
  for(int i = 1; i <= N; ++i){
    cin >> c[i];
    pq.push(mp(deg[i], i));
  }
  sort(c + 1, c + 1 + N);
  ll res = 0;
  for(int i = 1; i <= N; ++i){
    while(pq.size() && (deg[pq.top().se] != pq.top().fi || d[pq.top().se])) pq.pop();
    res += 1ll * c[i] * pq.top().fi;
    d[pq.top().se] = c[i];
    int u = pq.top().se; pq.pop();
    for(int v : adj[u]){
      if(d[v]) continue;
      deg[v]--;
      pq.push(mp(deg[v], v));
    }
  }
  cout << res << '\n';
  for(int i = 1; i <= N; ++i)
    cout << d[i] << ' ';
}
