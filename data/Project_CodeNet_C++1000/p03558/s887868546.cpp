#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n,dis[100005];
vector<pii> v[100005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[100005];
void dijkstra(){
    pq.push(mpr(0,0));
    rep(i,1,n) dis[i]=inf;
    while(!pq.empty()){
        pii g=pq.top();pq.pop();
        int c=g.se;
        if(vis[c]) continue;
        vis[c]=1;
        rap(i,0,v[c].size()){
            pii x=v[c][i];int to=x.fi,cost=x.se;
            if(dis[to]>dis[c]+cost){
                dis[to]=dis[c]+cost;
                pq.push(mpr(dis[c]+cost,to));
            }
        }
    }
}
void add(int x,int y,int c){
    v[x].pb(mpr(y,c));
}
int main()
{
    scanf("%d",&n);
    if(n==1){printf("1");return 0;}
    rep(i,1,n){
        add(i,(i==n?1:i+1),1);
        if(i!=(i-1)*10%n+1) add(i,(i-1)*10%n+1,0);
    }
    add(0,2,1);
    dijkstra();
    //rep(i,0,n) printf("%d%c",dis[i],i==n?'\n':' ');
    printf("%d\n",dis[1]);
    return 0;
}