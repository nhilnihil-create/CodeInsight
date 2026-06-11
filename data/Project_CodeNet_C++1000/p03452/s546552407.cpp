#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define mod2 1000000006
#define inf 1000000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<lli>
#define vii vector<int>
#define is indexed_set
#define eps 0.000001
#define endl '\n'
#define mo 998244353
#define pi 3.141592653589793
#define FF first
#define SS second
using namespace std ;
 
const lli dx4[] = {-1, 0, 1, 0};
const lli dy4[] = {0, 1, 0, -1};
const lli dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const lli dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
 
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count()); // can give negative values too

#define N 100001

bool ans=1;

vector<pll> v[N];
lli a[N];
bool vis[N];

void dfs(lli q,lli val)
{
    vis[q] = 1;
    a[q] = val;

    for(auto x:v[q])
    {
        if(!vis[x.ff])
        {
            dfs(x.ff , val+x.ss);
        }
    }
}

void solve()
{
    lli n,m;
    cin>>n>>m;

    loopl(i,1,n+1) a[i] = -1;


    while(m--)
    {
        lli x,y,r;
        cin>>x>>y>>r;

        v[x].pb({y,r});
        v[y].pb({x,-1*r});
    }

    loopl(i,1,n+1)
    {
        if(!vis[i])
            dfs(i,0);
    }

    // loopl(i,1,n+1) cout<<a[i]<<" ";
    // cout<<endl;

    loopl(i,1,n+1)
    {
        for(auto x:v[i])
        {
            if(a[i]+x.ss != a[x.ff])
            {
                cout<<"No";
                return ;
            }
        }
    }

    cout<<"Yes";
}   

int main()
{
////////////////////////////////////////////   
    fastio;
////////////////////////////////////////////
    
    lli t;
    t=1;
    while(t--)
    {
        solve();
    }
}
