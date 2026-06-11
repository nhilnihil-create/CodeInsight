#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


#define int ll

using edge =struct{int to;ll cost;};
vector <edge> tree[100010];
ll aa[100010];
bool used[100010];

void dfs(int v){
    used[v]=true;
    for(auto p:tree[v]){
        if(used[p.to]){
            if(aa[v]+p.cost!=aa[p.to]){
                cout<<"No"<<endl;
                exit(0);
            }
        }else{
            aa[p.to]=aa[v]+p.cost;
            dfs(p.to);
        }
    }
}


int n,m;
int a,b,c;

signed main(){
    cin>>n>>m;
    rep(i,0,m){
        cin>>a>>b>>c;
        a--,b--;
        tree[a].pb({b,c});
        tree[b].pb({a,-c});
    }
    rep(i,0,n){
        if(!used[i])dfs(i);
    }
    cout<<"Yes"<<endl;
    
    return 0;
}