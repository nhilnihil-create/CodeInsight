#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
vector<vector<int> >G(100010);
ll color[100010];
ll b,w;
bool dfs(int i,int c){
    bool f=1;
    if(c==1)b++;
    if(c==-1)w++;
    for(auto e:G[i]){
        if(color[i]==color[e]){
            f=0;break;
        }
        else if(color[e]==0){
            color[e]=-c;
            if(!dfs(e,-c)){
                f=0;break;
            }
        }
    }
    return f;
}

int main(){
    ll n,m;cin>>n>>m;
    b=0,w=0;
    rep(i,m){
        int a,b;cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    color[1]=1;
    if(dfs(1,1)){
        cout<<b*w-m<<endl;
    }else{
        cout<<(n*(n-1))/2-m<<endl;
    }
}