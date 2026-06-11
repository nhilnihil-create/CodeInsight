#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp12            make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq1             priority_queue<int>
#define pqr1            priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int modInv(int a,int b,int m){int res=1;a=a%m;while(b>0){if(b&1){res=(res*a)%m;}a=(a*a)%m;b=b>>1;}return res;}
int dp[100005];

int dfs(int src,vector<int> g[]){
    if(dp[src]!=-1) return dp[src];

    int ans=0;
    for(auto x:g[src]){
        ans=max(ans,dfs(x,g));
    }
    return dp[src]=ans+1;
}

void solve(){
	int n,m;
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    vector<int> g[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
    }
    int ans=0;
	for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i,g));
    }
    cout<<ans-1;
}
    

int32_t main()
{
    //FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
