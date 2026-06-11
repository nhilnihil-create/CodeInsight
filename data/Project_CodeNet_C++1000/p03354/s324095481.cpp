#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

int par[100010];
int rank_[100010];

void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    rank_[i] = 0;
  }
}

int find(int x){
  if(x==par[x]){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rank_[x]<rank_[y]){
    par[x]=y;
  }else{
    par[y]=x;
    if(rank_[x]==rank_[y]) rank_[x]++;
  }
}

bool same(int x, int y){
  return find(x)==find(y);
}
 
int main(){
  int n, m;
  cin >> n >> m;
  init(n);
  vector<int> s(n);
  for(int i=0; i<n; i++){
    cin >> s[i];
    s[i]--;
  }
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    unite(x,y);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    if(same(i, s[i])) ans++;
  }
  cout << ans << endl;
  return 0;
}
