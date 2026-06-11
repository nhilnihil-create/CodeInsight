#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>adj[501];
int sz[501];
int store[501][501];
int bs(int l,int r,int x,vector<int>v)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(v[mid]<=x)
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    return ans+1;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0; i<=500; i++)
    {
        sz[i]=adj[i].size();
        sort(all(adj[i]));
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            store[i][j]=bs(0,sz[i]-1,j,adj[i]);
        }
    }
    while(q--)
    {
        int x,y,ans=0;
        cin>>x>>y;
        for(int i=x; i<=n; i++)
        {
            //ans+=bs(0,sz[i]-1,y,adj[i]);
            ans+=store[i][y];
        }
        cout<<ans<<endl;

    }
    return 0;
}
