/***
بسم الله الرحمن الرحيم
اللهم ما صلّ على سيدنا محمد
اذكر الله
واتقوا يوما ترجعون فيه إلى الله ثم توفى كل نفس ما كسبت وهم لا يظلمون
****/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);

using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}

const ll OO=-1e18;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////
const int N = 1e6+1;
int mem[200005],n,m,mod=1e9+7,cnt;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
bool visited[200005];
vector <int> adj[200005];
int dfs(int s)
{
    int &ret=mem[s];
    if(~ret)return ret;
       ret=0;
      /// visited[s] = true;

    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            ret= max(ret, dfs(adj[s][i])+1);
        }
    }
    return ret;
}
int main()
{
    init();
    int x,y;
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int mx=0,mn=2000006;
    for(int i = 1; i <= n; ++i)
    {
            cnt= dfs(i);
            mx=max(cnt,mx);
        }

    cout<<mx;
}


