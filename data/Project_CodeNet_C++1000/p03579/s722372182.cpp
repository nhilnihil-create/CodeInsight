#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int colors[100005];

bool is_bipartite_graph(const vector<vector<int>> &G, int v, int c){
  colors[v] = c;
  for(int u : G[v]){
    if(colors[u] == c){
      return false;
    }
    if(colors[u] == 0 && !is_bipartite_graph(G, u, -c)){
      return false;
    }
  }
  return true;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  
  int a, b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if(is_bipartite_graph(G, 0, 1)){
    
    ll color1 = 0;
    ll color2 = 0;
    for(int i = 0; i < N; i++){
      if(colors[i] == 1){
        color1++;
      }else{
        color2++;
      }
    }

    cout << color1 * color2 - M << endl;

  }else{
    cout << N * (N-1) /2 - M << endl;
  }




  return 0;
}
