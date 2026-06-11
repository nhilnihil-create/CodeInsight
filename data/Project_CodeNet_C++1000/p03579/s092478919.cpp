#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

vector<vector<int> >adj;
int vis[100005][2];
int ans[2];
int tot=0;
void dfs(int ver,int x)
{
    ans[x]++;
    vis[ver][x]=1;

    for(auto i:adj[ver])
    {
        if(vis[i][(x+1)%2]==0)
            dfs(i,(x+1)%2);
    }   
}


signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    tot+=ans[0]*ans[1]-m;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i][0]+vis[i][1]==2)
            res++;
    }    
    tot-=res*res;
    tot+=(res*(res-1))/2;
    cout<<tot;
    
} 
    
