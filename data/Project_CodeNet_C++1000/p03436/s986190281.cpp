#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*--------------------------------------------------------------------*/


signed main(){
  int h,w;
  cin>>h>>w;
  int m[h][w];
  int cnt=0;//black
  rep(i,h){
    string s;
    cin>>s;
    rep(j,w){
      m[i][j]=(s[j]=='.'?0:1);
      cnt+=(s[j]=='#');
    }
  }
  // black:1, white:0

  // rep(i,h){
  //   rep(j,w) cout<<m[i][j];
  //   cout<<endl;
  // }

  queue<pii> q;
  vector<vi> d(h,vi(w,INF));
  d[0][0]=0;
  
  q.push(make_pair(0,0));
  while(!q.empty()){
    pii p=q.front();
    q.pop();
    int x=p.first,y=p.second;
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<0||nx>=h||ny<0||ny>=w||m[nx][ny]==1||d[nx][ny]<INF){
        continue;
      }
      d[nx][ny]=d[x][y]+1;
      q.push(make_pair(nx,ny));
    }
  }
  int ans=h*w-d[h-1][w-1]-1-cnt;

  if(d[h-1][w-1]==INF) ans=-1;

  cout<<ans<<endl;

  return 0;
}
