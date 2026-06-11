#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

vector<int> g[N];

int d[N];

int dfs(int u,int p)    {
    int R = u;

    for(int v : g[u])   if (v != p) {
        d[v] = d[u] + 1;

        int x = dfs(v,u);

        if (d[R] < d[x])
            R = x;
    }
    return  R;
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    for(int i = 1 ; i < n ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;

        g[x].pb(y);
        g[y].pb(x);
    }

    int L = dfs(1,0);   d[L] = 0;
    int R = dfs(L,0);

    if (d[R] % 3 == 1)
        cout << "Second";
    else
        cout << "First";
}