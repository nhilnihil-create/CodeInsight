#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

#define all(c) ((c).begin()), ((c).end())
const long long INF = (1ll << 50);
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  flow_type max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
};
/*
int main() {
  for (int n, m; scanf("%d %d", &n, &m) == 2; ) {
    graph g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      //g.add_edge(u, v, w);
      g.add_edge(u-1, v-1, w);
    }
    printf("%lld\n", g.max_flow(0, n-1));
  }
}
*/
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    //map<ll,multiset<ll>> mp;
    map<ll,ll> mp, used;
    rep(i,N){
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.rbegin(), A.rend());
    ll ans = 0;
    rep(i,N){
        REP(j,1,32){
            if(mp[A[i]] <= used[A[i]]) break;
            ll b = (1LL << j) - A[i];
            if(b > A[i]) break;
            if(b < 1) continue;
            if(A[i] != b){
                if(mp[b] > used[b]){
                    ans++;
                    used[b]++;
                    used[A[i]]++;
                }
            }else{
                if(mp[b] > used[b]+1){
                    ans++;
                    used[b]++;
                    used[A[i]]++;
                }
            }
            break;

        }
    }
    cout << ans << endl;
    /*
    rep(i,N){
        REP(j,1,31){
            ll b = (1 << j) - A[i];
            if(b < 1) continue;
            if(b == A[i]){
                B[i] = mp[b] - 1;
            }else{
                B[i] = mp[b];
            }
        }
    }*/
    /*graph G(2*N+2);
    //ll mm = 0;
    rep(i,N){
        REP(j,1,31){
            ll b = (1LL << j) - A[i];
            if(b < 1) continue;
            for(auto& id:mp[b]){
                if(i==id) continue;
                G.add_edge(i+1,N+id+1,1);
                //mm++;
            }
        }
    }*/
    //cout << mm << endl;
    /*rep(i,N){
        G.add_edge(0,i+1,1);
        G.add_edge(N+i+1,2*N+1,1);
    }*/
    //ll ans = G.max_flow(0,2*N+1);
    //cout << ans/2 << endl;
}
