#include <bits/stdc++.h>
#define ll long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(0);
#define rep(i, init, n) for (int i = init; i < n; i++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define gcd __gcd
using namespace std;
const ll mod = 1e9 + 7;
const int N = 1e5 + 10;
const ll MOD = 998244353;
vector<int> edge[N];

ll POW(ll base, ll exponent){
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

ll Inv(ll x){
    return POW(x, MOD - 2);
}

/*void DFS(int src){
    visited[src] = 1;
    //conc[c].pb(src);
    int mx = -1;
    for(auto i : edge[src]){
        if(!visited[i]){
            //par[i] = src;
            //depth[i] = depth[src] + 1;
            DFS(i);
            mx = max(ans[i], mx);
            //sub[src] += sub[i];
        }
        else mx = max(mx, ans[i]);
    }
    //sub[src]++;
    ans[src] = max(ans[src], mx + 1);
}

void BFS(int s, vector<int> &d){
    d[s] = 0;
    set<pair<int, int>> st;
    st.insert(mp(0, s));
    while (!st.empty()){
        pair<int, int> x = *(st.begin());
        st.erase(st.begin());
        int v = x.S;
        for (auto to : edge[v]){
            int u = to.F, w = to.S;
            if (d[u] > d[v] + w){
                if(d[u] != INT_MAX) st.erase(st.find(mp(d[u], u)));
                d[u] = d[v] + w;
                st.insert(mp(d[u], u));
            }
        }
    }
}

int dijkstra(int n){
    set<pair<int, int>> setds;
    vector<int> dist;
    dist.resize(n + 1, INT_MAX);
    setds.insert(mp(0, 1));
    dist[1]=0;
    while(!setds.empty()){
        pair<int, int> pu = *(setds.begin());
        setds.erase(setds.begin());
        int u = pu.S;
        vector<pair<int, int>> &temp = edge[u];
        for(int i = 0; i < (int)temp.size(); i++){
            int v = temp[i].F;
            int w = temp[i].S;
            if(dist[u] + w < dist[v]){
                if(dist[v] != INT_MAX)
                    setds.erase(setds.find(mp(dist[v], v)));
                dist[v] = dist[u] + w;
                setds.insert(mp(dist[v], v));
            }
        }
    }
    return dist[n];
}

void DFS_Mat(int x, int y){
    visited[x][y] = 1;
    //conc[c].pb(mp(x, y));
    if(x + 1 < n){
        if(s[x + 1][y] == '.' and !visited[x + 1][y]){
            DFS_Mat(x + 1, y);
            ans[x][y] = (ans[x][y] + ans[x + 1][y]) % mod;
        }
        else ans[x][y] = (ans[x][y] + ans[x + 1][y]) % mod;
        else if(s[x + 1][y] == '*'){
            f++;
        }
    }
    if(x - 1 >= 0){
        if(s[x - 1][y] == '.' and !vis[x - 1][y]){
            DFS_Mat(x - 1, y);
        }
        else if(s[x - 1][y] == '*'){
            f++;
        }
    }
    if(y + 1 < m){
        if(s[x][y + 1] == '.' and !visited[x][y + 1]){
            DFS_Mat(x, y + 1);
            ans[x][y] = (ans[x][y] + ans[x][y + 1]) % mod;
        }
        else ans[x][y] = (ans[x][y] + ans[x][y + 1]) % mod;
        else if(s[x][y + 1] == '*'){
            f++;
        }
    }
    if(y - 1 >= 0){
        if(s[x][y - 1] == '.' and !vis[x][y - 1]){
            DFS_Mat(x, y - 1);
        }
        else if(s[x][y - 1] == '*'){
            f++;
        }
    }
    if(x == n - 1 and y == m - 1) ans[x][y] = 1;
    //cout<<ans[x][y]<<'\n';
}*/

int main(){
    IOS
    int n;
    cin>>n;
    int x = 0, y = 0, z = 0;
    rep(i, 0, n){
        int t;
        cin>>t;
        if(t == 1) x++;
        else if(t == 2) y++;
        else z++;
    }
    double dp[n + 1][n + 1][n + 1];
    rep(i, 0, n + 1){
        if(!i) dp[i][0][0] = 0.0;
        else dp[i][0][0] = (double)n / i + dp[i - 1][0][0];
    }
    rep(j, 1, n + 1){
        rep(i, 0, n - j + 1){
            if(!i) dp[i][j][0] = (double)n / j + (double)j / j * dp[i + 1][j - 1][0];
            else dp[i][j][0] = (double)n / (i + j) + (double)j / (i + j) * dp[i + 1][j - 1][0] + (double)i / (i + j) * dp[i - 1][j][0];
        }
    }
    rep(k, 1, n + 1){
        rep(j, 0, n - k + 1){
            rep(i, 0, n - (k + j) + 1){
                dp[i][j][k] = (double)n / (i + j + k);
                if(i) dp[i][j][k] += (double)i / (i + j + k) * dp[i - 1][j][k];
                if(j) dp[i][j][k] += (double)j / (i + j + k) * dp[i + 1][j - 1][k];
                dp[i][j][k] += (double)k / (i + j + k) * dp[i][j + 1][k - 1];
            }
        }
    }
    cout<<fixed;
    cout<<setprecision(15)<<dp[x][y][z];
    return 0;
}