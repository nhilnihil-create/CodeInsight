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
ll vis[55][55];
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
int main(){
    cin>>h>>w;
    vector<string> g(h);
    rep(i,h)cin>>g[i];
    ll bc=0;
    rep(i,h){
        rep(j,w){
            if(g[i][j]=='#')bc++;
        }
    }
    queue<lll> q;
    q.push({{0,0},1});
    rep(i,55){
        rep(j,55){
            vis[i][j]=0;
        }
    }
    vis[0][0]=1;
    while(q.size()){
        lll now=q.front();q.pop();
        ll nowx=now.fi.fi,nowy=now.fi.se,nowc=now.se;
        rep(i,4){
            if(nowx+dx[i]<0||nowx+dx[i]>=h||nowy+dy[i]<0||nowy+dy[i]>=w)continue;
            if(g[nowx+dx[i]][nowy+dy[i]]=='#'||vis[nowx+dx[i]][nowy+dy[i]])continue;
            q.push({{nowx+dx[i],nowy+dy[i]},nowc+1});
            vis[nowx+dx[i]][nowy+dy[i]]=nowc+1;
        }
    }
    if(!vis[h-1][w-1]){
        cout<<-1<<endl;
        return 0;
    }
    ll grid=h*w;
    ll ans=grid-bc-vis[h-1][w-1];
    cout<<ans<<endl;
    return 0;
}