#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int par[100005];
int rnk[100005];
int cnt[100005];

void init(int n) {
  for (int i=0; i<n; i++) {
    par[i]=i;
    rnk[i]=0;
    cnt[i]=1;
  }
}
int find(int x) {
  if (par[x]==x) {
    return x;
  }
  else {
    return par[x]=find(par[x]);
  }
}

void unite(int x,int y) {
  x=find(x);
  y=find(y);
  if (x==y) return;
  if (rnk[x]<rnk[y]) {
    par[x]=y;
    cnt[y]+=cnt[x];
  }
  else {
    par[y]=x;
    cnt[x]+=cnt[y];
    if (rnk[x]==rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y) {
  return find(x)==find(y);
}


int main(){
  int n,m;
  cin>>n>>m;
  int p[100005];
  rep(i,n){
    int a;
    cin>>a;
    a--;
    p[a]=i;
  }
  init(n);
  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--; y--;
    unite(x,y);
  }
  int ans=0;
  rep(i,n){
    if(find(i)==find(p[i])) ans++;
  }
  cout<<ans<<endl;
  return 0;
}



