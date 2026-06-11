#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

int par[100005];
ll rank_[100005];
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    rank_[i] = 1;
  }
}

int find(int x){
  if(x==par[x]){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

ll unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return 0;
  ll tmp = rank_[x]*rank_[y];
  if(rank_[x]<rank_[y]){
    par[x]=y;
    rank_[y] += rank_[x];
    rank_[x] = rank_[y];
    return tmp;
  }else{
    par[y]=x;
    rank_[y] += rank_[x];
    rank_[x] = rank_[y];
    return tmp;
  }
}

bool same(int x, int y){
  return find(x)==find(y);
}

 
int main(){
  int n, m;
  cin >> n >> m;
  init(n);
  vector<P> G;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.push_back(make_pair(a,b));
  }
  vector<ll> cnt(m);
  for(int i=m-1; i>=0; i--){
    cnt[i] = unite(G[i].first, G[i].second);
  }
  cout << cnt[0] << endl;
  for(int i=1; i<m; i++){
    cnt[i] += cnt[i-1];
    cout << cnt[i] << endl;
  }
  
  return 0;
}
