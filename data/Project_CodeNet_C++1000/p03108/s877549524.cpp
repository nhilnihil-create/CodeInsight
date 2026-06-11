#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;

vector<ll>par,len,Size;

ll find(ll x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(len[x] < len[y]) par[x] = par[y];
    else par[y] = par[x];
    if(len[x] == len[y]) len[x]++;
    ll sx = Size[x];
    ll sy = Size[y];
    Size[x] += sy;
    Size[y] += sx;
}

int main()
{
    ll N,M; cin >> N >> M;
    vector<pair<ll,ll>>G(M);
    for(ll i = 0; i < M; i++)
    {
        ll a,b; cin >> a >> b;
        a--,b--;
        G[M-1-i] = pair(a,b); 
    }
    vector<ll>ans(M+1);
    ans[0] = 0;
    ans[M] = N*(N-1)/2;
    len.assign(N,0);
    par.resize(N);
    Size.assign(N,1);
    for(ll i = 0; i < N; i++) par[i] = i;
    for(ll i = 0; i < M-1; i++)
    {
        if(find(G[i].first) == find(G[i].second)) 
        {
            ans[M-i-1] = ans[M-i];
            continue;
        }
        ans[M-i-1] = ans[M-i] - Size[find(G[i].first)]*Size[find(G[i].second)];
        unite(G[i].first,G[i].second);
    }
    for(int i = 1; i <= M; i++) cout << ans[i] << endl;
}