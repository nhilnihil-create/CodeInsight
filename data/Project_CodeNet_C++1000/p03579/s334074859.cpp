#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t
 
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
const ll MOD=1000000007,INF=1e18;

int N,M;
int group[200020];
vint g[200020];
int flag=1;

void dfs(int now,int tmp){
    group[now]=tmp;
    tmp^=1;
    for(auto e:g[now]){
        if(group[e]==-1)dfs(e,tmp);
        else if(group[e]!=tmp)flag=0;
    }
}

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    //MOD同士の引き算に注意
    cin>>N>>M;
    rep(i,0,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    memset(group,-1,sizeof(group));
    dfs(0,1);
    if(flag==0)cout<<N*(N-1)/2-M<<endl;
    else{
        int cnt=0;
        rep(i,0,N)if(group[i]==1)cnt++;
        cout<<cnt*(N-cnt)-M<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}