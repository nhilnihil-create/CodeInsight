#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define tle ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 998244353;
const int mxn = 1e6 +7;
ll _,n,m,t,k,u,v,ans,cnt,ok,lim;
ll w[mxn] , cost[mxn] ,  far[mxn] , siz[mxn];
char ch;
#define lc now<<1
#define rc now<<1|1
string str ;
ll a[mxn];
struct node{int u,v;}p[mxn];
void init(){for(int i=1;i<=n;i++) far[i] = i , siz[i] = 1 ;}
ll root(ll x)
{
    if(x==far[x]) return x;
    return far[x] = root( far[x] ) ;
}
void up(ll u,ll v)
{
    u = root(u) ; v = root(v) ;
    if(u!=v){
        far[v] = u ;
        ///cout<<siz[v]<<" "<<siz[u]<<endl;
        ans+=siz[u]*siz[v]*1ll;
        siz[u]+=siz[v];
    }
}
int main()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>p[i].u>>p[i].v;
    }
    lim = n*(n-1)/2; ans = 0 ;
    for(int i=m;i>0;i--)
    {
        a[i] = lim - ans ;
        /// cout<<far[ p[i].u ]<<" "<<far[ p[i].v ]<<endl;
        /// cout<<"     ---- " << ans<<endl;
        up(p[i].u,p[i].v);
    }
    for(int i=1;i<=m;i++)
        cout<<a[i]<<endl;
}