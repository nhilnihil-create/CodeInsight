#include<bits/stdc++.h>

using namespace std;

#define X   first
#define Y   second

const int   N   = 2e5 + 1;

typedef pair<int,int>   ii;

vector<int> g[N];
int n, m, s[N];
set<ii> S[2];
int c[N][2];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 1 ; i <= n ; ++i)   {
        char c; cin >> c;
        s[i] = c - 'A';
    }

    while(m--)  {
        int x, y;   cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        c[x][s[y]]++;
        c[y][s[x]]++;
    }

    for(int i = 1 ; i <= n ; ++i)   {
        S[0].insert(ii(c[i][0],i));
        S[1].insert(ii(c[i][1],i));
    }

    while(1)    {
        if(S[0].empty())
            return 0 * puts("No");
        if ((*S[0].begin()).X && (*S[1].begin()).X)
            return 0 * puts("Yes");
        int u = (*S[0].begin()).Y;
        if(c[u][0])
            u = (*S[1].begin()).Y;
        S[0].erase(ii(c[u][0],u));
        S[1].erase(ii(c[u][1],u));
        for(int v : g[u])   {
            if(S[0].find(ii(c[v][0],v)) == S[0].end())
                continue;
            S[0].erase(ii(c[v][0],v));
            S[1].erase(ii(c[v][1],v));
            c[v][s[u]]--;
            S[0].insert(ii(c[v][0],v));
            S[1].insert(ii(c[v][1],v));
        }
    }
}
