/*

A：1...n
B：1...n


*/
#include<bits/stdc++.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const ll MAXN=1e6+5;
const ll INF=1e18;
const ll MOD=1e9+7;
ll n,m,mypow[20],a[MAXN];
multiset<ll,greater<ll> >ms[MAXN];
void init()
{
    mypow[0]=1;
    for(ll i=1;i<=20;i++)
    {
        mypow[i]=mypow[i-1]*2;
    }
}
void setunion(ll j,ll i)
{
    for(auto it=ms[i].begin();it!=ms[i].end();it++)
    {
        ms[j].insert(*it);
    }
}
bool addable(ll j,ll i)
{
    return (j&(1<<i))==0;
}
void refine(ll x)
{
    while(ms[x].size()>2)
    {
        ms[x].erase(--ms[x].end());
    }
}
void solve()
{
    for(ll i=0;i<m;i++)
    {
        ms[i].insert(a[i]);
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(addable(j,i))
            {
                setunion(j|(1<<i),j);
                refine(j|(1<<i));
            }
        }
    }
    ll pre=0;
    for(ll i=1;i<m;i++)
    {
        pre=max(pre,(*ms[i].begin())+(*(++ms[i].begin())));
        printf("%lld\n",pre);
    }

}
int main()
{
    init();
    scanf("%lld",&n);
    m=mypow[n];
    for(ll i=0;i<m;i++)
    {
        scanf("%lld",&a[i]);
    }
    solve();
}
