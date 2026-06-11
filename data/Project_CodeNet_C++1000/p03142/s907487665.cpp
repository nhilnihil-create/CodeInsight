#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ff first
#define ss second
#define input(a) scanf("%lld",&a)
#define M 1000000007
#define inf 1<<30

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;

ll gcd(ll a,ll b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

ll bigMod(ll base,ll power)
{
    if(power==0)
        return 1;
    ll x=bigMod(base,power/2);
    x=(x*x)%M;
    if(power&1)
        x=(x*base)%M;
    return x;
}

ll n,m,u,v,flg[100100],par[100100];

vector<ll>lst[100100];
stack<ll>tp;

void dfs(int n)
{
    if(flg[n])
        return;
    flg[n]=1;
    for(int i=0;i<lst[n].size();i++)
        dfs(lst[n][i]);
    tp.push(n);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<n+m;i++){
        cin>>u>>v;
        lst[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        dfs(i);
    while(!tp.empty()){
        v=tp.top();
        for(int i=0;i<lst[v].size();i++)
            par[lst[v][i]]=v;
        tp.pop();
    }
    for(int i=1;i<=n;i++)
        cout<<par[i]<<endl;
    return 0;
}

