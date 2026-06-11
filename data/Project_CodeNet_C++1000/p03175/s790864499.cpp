#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define INF (int)1e9+1
#define INFLL (int)1e18+1
#define sz(bb) (int)bb.size()
#define all(qq) qq.begin(), qq.end() 
#define Max(a, b, c) max(a, max(b, c))
#define Min(a, b, c) min(a, min(b, c))
const double PI=acos(-1);
// #define int unsigned long long int//used when x<=2^64-1 && x>0
#define int long long//used when x<=2^63-1
//bool cmp if returns true it keeps 1st as first else swaps
typedef long long  ll;

const int N=100005;
vector<int> gr[N];
int white[N], black[N];
void fun(int x, int par)
{
    black[x]=1;
    white[x]=1;
    for(auto it: gr[x])
    {
        if(it==par)
            continue;
        fun(it, x);
        white[x]*=white[it]+black[it];
        black[x]*=white[it];
        white[x]%=mod;
        black[x]%=mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    memset(white, 0, sizeof(white));
    memset(black, 0, sizeof(black));
    fun(1, -1);
    cout<<(white[1]+black[1])%mod<<"\n";
}
int32_t main()
{
    IOS;
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}