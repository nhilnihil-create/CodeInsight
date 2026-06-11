#include <bits/stdc++.h>
#define eps 1e-9
#define mod 1000000007
#define pi 3.14159265359
#define inf 1e18

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, x, y;
vector<ll> V[200005];
ll dp[200005];

ll DFS(ll x, ll &dist, ll &target, ll lvl = 0, ll last = -1)
{
    if (lvl > dist)
    {
        dist = max(dist, lvl);
        target = x;
    }
    for (auto i : V[x])
    {
        if (i == last)
            continue;
        DFS(i, dist, target, lvl+1, x);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (ll i=1; i<n; i++)
    {
        cin>>x>>y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    if (n==1)
    {
        cout<<"First";
        return 0;
    }

    ll d = 0;
    ll far1;
    DFS(1, d, far1);

    d = 0;
    ll far2;
    DFS(far1, d, far2);
    dp[0] = 1;
    dp[1] = 0;
    for (ll i=2; i<=d; i++)
    {
        dp[i] = (dp[i-1] == 0) || (dp[i-2] == 0);
    }
    // cout<<d<<endl;
    if (dp[d] == 1)
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}