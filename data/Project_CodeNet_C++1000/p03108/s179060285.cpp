#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>

const ll sz=1e5+100;
ll parent[sz], ran[sz];
ll ans=0;

void init(ll n)
{
    for(ll i=0;i<=n;i++) parent[i]=i, ran[i]=1;
}

ll Find(ll x)
{
    if(parent[x]==x) return x;
    else return (parent[x]=Find(parent[x]));
}

void Union(ll a,ll b)
{
    ll x=Find(a);
    ll y=Find(b);
    if(x==y) return ;
    ll p=ran[x], q=ran[y];
    ans-=(p*q);

    if(ran[x]>ran[y]){
       ran[x]+=ran[y];
       parent[y]=x;
    }
    else{
        ran[y]+=ran[x];
        parent[x]=y;
    }
}

int main()
{
    ll n,m,i,j,k;
    cin>>n>>m;

    pii ara[m];
    ans=(n*(n-1))/2ll;

    for(i=0;i<m;i++) cin>>ara[i].first>>ara[i].second;
    ll mem[m];

    init(n);
    for(i=m-1;i>=0;i--){
        mem[i]=ans;
        Union(ara[i].first, ara[i].second);
    }

    for(i=0;i<m;i++) cout<<mem[i]<<'\n';
}
