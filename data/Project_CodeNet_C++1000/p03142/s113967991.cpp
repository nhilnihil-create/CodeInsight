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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  
  vector<vector<int>> G(N);
  vector<vector<int>> Ginv(N);
  vector<int> is_child(N);

  vector<int> h(N);

  int a, b;
  for(int i = 0; i < N-1+M; i++){
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    h[b]++;
    Ginv[b].push_back(a);
    is_child[b] = 1;
  }

  int root = 0;
  for(int i = 0; i < N; i++){
    if(is_child[i] == 0){
      root = i;
    }
  }

  vector<int> parent(N);

  stack<int> st;
  st.push(root);

  vector<int> topo;
  while(st.size()){

    int v = st.top(); st.pop();
    topo.push_back(v);

    for(auto& nv : G[v]){
      h[nv]--;
      if(h[nv] == 0) st.push(nv);
    }
  }

  vector<int> topo_order(N);
  for(int i = 0; i < N; i++){
    topo_order[topo[i]] = i;
  }
  
  for(int i = 0; i < N; i++){
    // 自分にはいってくる中で、一番トポロジカル順序が遅い（大きいやつ）
    int tmp = -1;
    for(auto nv : Ginv[i]){
      if(chmax(tmp, topo_order[nv])) parent[i] = nv+1;
    }
  }

  for(int i = 0; i < N; i++){
    cout << parent[i] << endl;
  }

  return 0;
}
