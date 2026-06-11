///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define u64 uint64_t
#define ll long long
#define endl "\n"
#define PI acos(-1)
#define fi first
#define si second
#define mp make_pair
#define pb push_back
#define set0(arr) memset(arr,0,sizeof(arr))
#define setinf(arr) memset(arr,126,sizeof(arr))
#define vsort(v) sort(v.begin(),v.end())
#define all(x) (x).begin(),(x).end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
using pll = pair<ll,ll>;
using vl = vector<ll>;
using vpll = vector<pll>;
using mll = map<ll,ll>;
using mcl = map<char,ll>;
using sl = set<ll>;
using sc = set<char>;
using dl = deque<ll>;
ll mod=1e9+7;
const int N=1e6+5;
vl adj[200005];
vpll adjc[200005];
ll vis[200005],dis[200005];
ll arr[N];
void dfs(ll x)
{
    vis[x]=1;
    for(ll i=0;i<adjc[x].size();i++)
    {
        auto p=adjc[x][i];
        if(!vis[p.first])
        {
            dis[p.first]=dis[x]+p.second;
            dfs(p.first);
        }
    }
}
int main()
{
    IOS;
    ll a,b,c,d,sz,n,m,p,x,y,z,i,j,k,f=0,tc,cnt=0,sum=0,mul=1,mi=1e18,ma=-1e18;
    string str;
    char ch;
    double db;
    //code
    cin>>n;
     set0(vis);
    for(i=1;i<n;i++)
    {
        cin>>a>>b>>c;
        adjc[a].pb({b,c});
        adjc[b].pb({a,c});
    }
    dis[1]=0;
    dfs(1);
   for(i=1;i<=n;i++)
   {
       cout<<dis[i]%2<<endl;
   }



    //code
    return 0;
}
