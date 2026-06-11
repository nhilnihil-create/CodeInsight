#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

bool vis[60], g[60][60];
vector<int> G[60];
int a[60], b[60];

void dfs(int u)
{
    if(vis[u])
        return;
    vis[u] = true;

    for(auto i: G[u]){
        if(g[u][i])
            dfs(i);
    }
}

int main()
{
    int m, n;
    cin >> n >> m;


    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];

        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
        G[a[i]].Pb(b[i]);
        G[b[i]].Pb(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        g[a[i]][b[i]] = g[b[i]][a[i]] = false;

        mem(vis, false);
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j])
                cnt++, dfs(j);

        g[a[i]][b[i]] = g[b[i]][a[i]] = true;

        if(cnt > 1)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}
