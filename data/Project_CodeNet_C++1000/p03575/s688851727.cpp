#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll MOD=1e9+7;

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%13;
        a=a*a%13;
        x>>=1;
    }
    return res;
}

vector<vector<int> > G(50,vector<int>(50,0));
vector<int> cl(50,0);
int n,m;
void dfs(int x,int c){
    cl[x]=c;
    for(int y=0;y<n;y++)if(G[x][y]==1){
        if(cl[y]==0) dfs(y,c);
    }
}
int main(){
    cin>>n>>m;
    vector<int> a(m),b(m);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        G[a[i]][b[i]]=G[b[i]][a[i]]=1;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int cnt=0;
        G[a[i]][b[i]]=G[b[i]][a[i]]=0;
        fill(cl.begin(),cl.end(),0);
        for(int i=0;i<n;i++)if(cl[i]==0){
            cnt++;
            dfs(i,cnt);
        }
        if(cnt>1) ans++;
        G[a[i]][b[i]]=G[b[i]][a[i]]=1; 
    }
    cout<<ans<<endl;
    return 0;
}