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
#define mid (low+high)/2
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n,m;
vector < pi > info[N];
ll a,b,c;
ll dist[N];
bool vis[N];
bool can = true;

void dfs(ll cur,ll d)
{
    if(vis[cur])
    {
        if(dist[cur] != d)
            can = false;

        return;
    }

    vis[cur] = true;
    dist[cur] = d;

    rep(i,0,info[cur].size())
    {
        dfs(info[cur][i].first,d+info[cur][i].second);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    rep(i,0,m)
    {
        cin >> a >> b >> c;

        info[a].push_back(mp(b,c));
        info[b].push_back(mp(a,-c));
    }

    rep(i,1,n+1)
    {
        if(!vis[i])
        {
            dfs(i,0);
        }
    }

    if(can)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

