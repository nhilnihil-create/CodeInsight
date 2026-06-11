#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod= 1000000007;

vector<ll> g[100001];
ll black[100001], white[100001];

void dfs(ll current, ll parent)
{
    if(white[current]!=0)
    {
        return;
    }
    white[current]=1;
    black[current]=1;
    for(auto child: g[current])
    {
        if(child!=parent)
        {
            dfs(child, current);

            black[current]*=white[child];
            black[current]%=mod;

            white[current]*=((white[child]+black[child])%mod);
            white[current]%=mod;
       
        }
    }
}

int main()
{

    ll n;
    cin >> n;
   
   
    for(int i=0; i<n-1; i++)
    {
        ll x, y;
        cin >> x >>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    cout << (black[1] + white[1])%mod;

}