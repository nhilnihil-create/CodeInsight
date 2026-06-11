#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+5;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;

#define  sf scanf
#define  pf printf

#define  input freopen("input.txt","r",stdin)
#define  output freopen("output.txt","w",stdout)

#define  inf 1e8
#define  ff first
#define  ss second
#define  MP make_pair
#define  pb push_back
#define  all(v) v.begin(), v.end()
#define  printcase(cases) printf("Case %d:", cases);
#define  Unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define  FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define  endl printf("\n")
#define  __lcm(a, b) ((a*b)/__gcd(a, b))

int  Set(int N,int pos){return N=N | (1<<pos);}
int  reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
vector<pii>adj[mx];
int dis[mx];
int k;

int bfs(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(make_pair(0, src));
    for(int i = 0; i < mx; i++) dis[i] = inf;
    dis[src] = 0;
    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int u = top.ss;
        int curw = top.ff;
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            if(w+curw<dis[v])
            {
                dis[v] = curw+w;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
    //for(int i = 0; i < k; i++) cout << dis[i] << ' ';
    //cout << '\n';
    return dis[k];
}
int main()
{
    sf("%d", &k);

    for(int x = 0; x <= k; x++)
    {
        for(int p = 0; p <= 9; p++)
        {
            int u = x;
            int v = ((10*x)+p)%k;
            if(v == 0) v = k;
            if(v==k && u==0 && p==0) continue;
            adj[u].push_back(make_pair(v, p));
        }
    }
    int ans = bfs(0);
    pf("%d\n", ans);
    return 0;
}
