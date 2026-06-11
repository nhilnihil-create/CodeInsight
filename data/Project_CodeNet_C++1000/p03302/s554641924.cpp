#include<bits/stdc++.h>
#define ll long long
#define thekingisborn ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ld  long double
#define f first
#define se second
#define pb push_back
#define maxn 200005
#define mod 1000000007
#define pi 3.14159265359

using namespace std;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

/*ll power(ll a,ll n)
{
    if(n == 1)return a%mod;
    if(n == 0)return 1;
    a = a%mod;
    if(n&1)return ((a%mod)*(power((a*a)%mod,n>>1))%mod)%mod;
    return power((a*a)%mod,n>>1)%mod;
}
ll gcd(ll a,ll b)
{
    if(a%b == 0)return b;
    return gcd(b,a%b);
}*/
/*int root(int x)
{
    while(par[x] != x)
    x = par[x];
    return x;
}
void dsu(int x,int y)
{
  if(root(x) == root(y))return;
  par[root(y)] = root(x);
  return;
}
void dfs(int x)
{
    done[x] = true;
    for(int i=0;i<int(adj[x].size());++i)
    {
        int y = adj[x][i];
        if(!done1[y])
        dfs(y);
    }
}*/
ll n;
vector<ll>v(3*maxn);

int main()
{
    thekingisborn;
    /*cin >> n;
    for(int i=0;i<(1<<n);++i)
    cin >> v[i];*/
    int a,b;
    cin >> a >> b;
    if(a+b == 15)
    cout << '+';
    else if(a*b == 15)
    cout << '*';
    else cout << 'x';
    return 0;
}
