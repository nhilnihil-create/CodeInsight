#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

char grid[1010][1010];
bool seen[1010][1010];
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};

int main(){
  int h,w;
  cin>>h>>w;
  queue<P> q;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
    seen[i][j]=0;
    if(grid[i][j]=='#'){
      seen[i][j]=1;
      q.push(make_pair(i,j));
    }
  }
  int ans=0;
  while(true){
    bool ok=1;
    rep(i,h)rep(j,w){
      if(!seen[i][j]){
        ok=0; break;
      }
    }
    if(ok) break;
    queue<P> r;
    ans++;
    while(!q.empty()){
      int pi,pj;
      tie(pi,pj)=q.front(); q.pop();
      rep(i,4){
        int ni=pi+di[i],nj=pj+dj[i];
        if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
        if(seen[ni][nj]) continue;
        seen[ni][nj]=1;
        r.push(make_pair(ni,nj));
      }
    }
    q=r;
  }
  cout<<ans<<endl;
}