#include <bits/stdc++.h>
#define BPhuong ""
#define maxn  100005
#define maxm
#define fi(i,a,b) for(int i = a; i<= b; i++)
#define fid(i,a,b) for(int i = a; i>= b; i--)
#define se second
#define f first
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define bit(x, i) ((x>>i)&1)
#define oo 1e9
struct data{
    int x, y, z;
};
using namespace std;
int n, pa[maxn], mod;
ll  l[maxn][2];
vector <int> a[maxn];
void dfs(int u)
{
    l[u][1] = 1;
    l[u][0] = 1;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(pa[u] != v)
        {
            pa[v] = u;
            dfs(v);
            l[u][0] *= ( (l[v][1] + l[v][0]) % mod );
            l[u][1] *= l[v][0];
            l[u][0] %= mod;
            l[u][1] %= mod;
        }
    }
}
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n;
    mod = 1e9 + 7;
    fi(i, 1, n-1)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

void xuli(){
    dfs(1);
    cout << ( l[1][0] + l[1][1]) % mod;
}

int main(){
    nhap();
    xuli();
}
