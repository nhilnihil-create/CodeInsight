//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize(4)
//#pragma GCC optimize("unroll-loops")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
//#include <bits/extc++.h>
#define fi first
#define se second
#define db double
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pi acos(-1.0)
#define ll long long
#define vi vector<int>
#define mod 1000000007
#define ld long double
//#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define ull unsigned long long
#define bpc __builtin_popcount
//#define base 1000000000000000000
#define fin freopen("a.txt","r",stdin)
#define fout freopen("a.txt","w",stdout)
#define fio ios::sync_with_stdio(false);cin.tie(0)
#define mr mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void sub(ll &a,ll b){a-=b;if(a<0)a+=mod;}
inline void add(ll &a,ll b){a+=b;if(a>=mod)a-=mod;}
template<typename T>inline T const& MAX(T const &a,T const &b){return a>b?a:b;}
template<typename T>inline T const& MIN(T const &a,T const &b){return a<b?a:b;}
inline ll qp(ll a,ll b){ll ans=1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod,b>>=1;}return ans;}
inline ll qp(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c,b>>=1;}return ans;}

using namespace std;
//using namespace __gnu_pbds;

const ull ba=233;
const db eps=1e-5;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=200000+10,maxn=1000000+10,inf=0x3f3f3f3f;

vi v[N];
int d[N];
void dfs(int u,int f,int &o)
{
    for(int x:v[u])if(x!=f)
    {
        d[x]=d[u]+1;
        dfs(x,u,o);
    }
    if(d[o]<d[u])o=u;
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        v[a].pb(b),v[b].pb(a);
    }
    int x1=1,x2=1;
    d[1]=1;dfs(1,0,x1);
    d[x1]=1;dfs(x1,0,x2);
    if(d[x2]%3==2)puts("Second");
    else puts("First");
    return 0;
}
/********************

********************/
