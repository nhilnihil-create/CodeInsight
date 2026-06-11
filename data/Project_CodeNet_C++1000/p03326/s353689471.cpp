 
/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x)     x.begin(),x.end()
#define tc   int tt; scf(tt); while(tt--)
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
typedef double dd;
using namespace std;
const ll M =1e9+7;
const int N = 1e5+7;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

// vector<int> adj[N];
// bool vis[N]={0};

// void dfs(int x)
// {
//     vis[x]=1;
        
//     for(auto it:adj[x])   
//     if(!vis[it])
//     dfs(it);
        
// }




int main()
{
    ll n,m,ans=0;
    lscf(n),lscf(m);

    ll a[N][3];

    rep(i,1,n+1)
    {
        rep(j,0,3)
        lscf(a[i][j]);
    }

    rep(i,0,8)
    {
        vector<ll>v;


        rep(j,1,n+1)
        {
             ll x=0;

            rep(k,0,3)
            {
                if((i/(1<<k))%2==0) 
                    x+=a[j][k];

                 else x-=a[j][k];
            }
            
            v.pb(x);
        
        }

        sort(all(v),greater<ll>());

            ll val=0;

        rep(l,0,m)
        val+=v[l];

        ans=max(ans,val);
    }
    

 

    lprin(ans);
    
    }