#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 17
#define INF 1e9+7

using namespace std;

int n,ar[N][N];
ll dp[(1 << N)];
bool vis[(1 << N)];
bool vis2[(1 << N)];
ll value[(1<<N)];

bool ison(ll mask,ll i)
{
    return (mask >> i)&1;
}

ll get_val(ll mask)
{
    if(vis2[mask])
        return value[mask];
    vis2[mask] = true;
    ll res=0;

    rep(i,0,n)
        if(ison(mask,i))
            rep(j,0,i)
                if(ison(mask,j))
                    res+=ar[i][j];

    return value[mask]=res;
}

ll solve(int mask)
{
    if(vis[mask])
        return dp[mask];

    vis[mask] = true;

    ll res = 0;

    for(int sub = mask;sub >= 0;sub = (sub-1)&mask)
    {
        ll cur = solve(mask^sub)+get_val(sub);

        res = max(res,cur);

        if(sub == 0)
            break;
    }

    return dp[mask] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    rep(i,0,n)
    {
        rep(j,0,n)
        {
            cin >> ar[i][j];
        }
    }

    cout << solve((1 << n)-1);

    return 0;
}
