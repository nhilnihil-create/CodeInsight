#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
    int h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];
  int ans=0;
  vector<vector<int>> dist(h,vector<int>(w,INF));
  queue<P> q;
  auto update=[&](int i,int j,int x){
    if(dist[i][j]!=INF) return;
    dist[i][j]=x;
    q.push(P(i,j));// .emplace(i,j)
  };
  update(0,0,0);
  while(!q.empty()){
    int i=q.front().first;
    int j=q.front().second; q.pop();
    rep(dir,4){
      int ni=i+di[dir], nj=j+dj[dir];
      if(ni<0||ni>=h||nj<0||nj>=w) continue;
      if(s[ni][nj]=='#') continue;
      update(ni,nj,dist[i][j]+1);
    }
  }
  ans=dist[h-1][w-1];
  if(dist[h-1][w-1]==INF){
    cout<<-1<<endl;
    return 0;
  }
  ans++;
  int sum=0;
  rep(i,h)rep(j,w){
    if(s[i][j]=='.') sum++;
  }
  cout<<sum-ans<<endl;
}