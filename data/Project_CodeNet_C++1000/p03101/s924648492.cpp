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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = (a-c) * (b-d);
  cout << ans << endl;
  return 0;
}
