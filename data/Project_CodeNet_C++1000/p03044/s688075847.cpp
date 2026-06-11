#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define flsh fflush(stdout)
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1000000000007
 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;


// void solve()
// {
//     string s;
//     cin>>s;
//     ll x1=s[0]-'a';
//     ll x2=s[1]-'a';
//     ll x3=s[2]-'a';
//     ll x4=s[3]-'a';
//     ll f1=0,f2=0;

     
    
    
// }
const int N=1e5+5;
vector<pll> v[N];
ll vis[N];
ll ans[N];

ll f=0;

void holve(ll x,ll col,ll s)
{
    vis[x]=1;
    ans[x]=col;
    
    for(auto it:v[x])
    {
        if(!vis[it.first])
        {
            if(it.second%2==0)
            {
                holve(it.first,col,x);   
            }
            else{
                holve(it.first,1-col,x);
            }
        }
    }
}


void solve()
{
    ll n;
    cin>>n;
    ll u,vv,dis;
    ll i,j;
    clr(ans);
    for(i=0;i<n-1;i++)
    {
        cin>>u>>vv>>dis;
        u--,vv--;
        v[u].pb(mp(vv,dis));
        v[vv].pb(mp(u,dis));
    }
    ll lef=-1;

   
    for(i=0;i<n;i++)
    {
       ll si = v[i].size();
       if(si==1)
       {
           lef=i;
           break;
       }
    }
     f=0;
     ll col2 = v[lef][0].second;
     if(col2%2==0)
     {
         col2=1;
     }
     else{
         col2=0;
     }
     holve(lef,col2,-1);
    //  clr(vis);
    //  holve(lef,1,-1);
        for(i=0;i<n;i++)
        {
            cout<<ans[i]<<"\n";
        }
    
    
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


// cin>>t;


while(t--)
{
solve();
} 


return 0;
}