#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll h,w;
ll vis[1010][1010];
int main(){
    cin>>h>>w;
    vs g(h);
    rep(i,h)cin>>g[i];
    queue<lll> q;
    rep(i,1010){
        rep(j,1010){
            vis[i][j]=-1;
        }
    }
    rep(i,h){
        rep(j,w){
            if(g[i][j]=='#'){
                q.push({{i,j},0});
                vis[i][j]=0;
            }
        }
    }
    while(q.size()){
        lll now=q.front();q.pop();
        ll nowx=now.fi.fi,nowy=now.fi.se,nowc=now.se;
        rep(i,4){
            if(nowx+dx[i]<0||nowx+dx[i]>=h||nowy+dy[i]<0||nowy+dy[i]>=w)continue;
            if(vis[nowx+dx[i]][nowy+dy[i]]>=0)continue;
            q.push({{nowx+dx[i],nowy+dy[i]},nowc+1});
            vis[nowx+dx[i]][nowy+dy[i]]=nowc+1;
        }
    }
    ll ans=0;
    rep(i,h){
        rep(j,w){
            chmax(ans,vis[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}