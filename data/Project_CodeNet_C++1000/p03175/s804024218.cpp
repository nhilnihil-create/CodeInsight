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
const ll N = 1e5 + 10;
const ll MOD = 998244353;
vector<ll> edge[N];
vector<bool> visited(N, 0);
int dp[N][2];

ll POW(ll base, ll exponent){
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

ll Inv(ll x){
    return POW(x, mod - 2);
}

void DFS(ll src){
    visited[src] = 1;
    //dp[src][0] = 0, dp[src][1] = 0;
    ll ans1 = 1, ans2 = 1;
    for(auto i : edge[src]){
        if(!visited[i]){
            DFS(i);
            //dp[src][1] = (dp[src][1] + ((dp[i][0] + dp[i][1]) % mod)) % mod;
            //dp[src][0] = (dp[src][0] + dp[i][1]) % mod;
            ans1 = ((ans1 * dp[i][1]) % mod + (ans1 * dp[i][0]) % mod) % mod;
            ans2 = (ans2 * dp[i][1]) % mod;
        }
    }
    dp[src][1] = ans1, dp[src][0] = ans2;
}

/*void BFS(int s, vector<int> &d){
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
    if(x + 1 < n){
        if(s[x + 1][y] == '.' and !visited[x + 1][y]){
            DFS_Mat(x + 1, y);
        }
    }
    if(x - 1 >= 0){
        if(s[x - 1][y] == '.' and !visited[x - 1][y]){
            DFS_Mat(x - 1, y);
        }
    }
    if(y + 1 < m){
        if(s[x][y + 1] == '.' and !visited[x][y + 1]){
            DFS_Mat(x, y + 1);
        }
    }
    if(y - 1 >= 0){
        if(s[x][y - 1] == '.' and !visited[x][y - 1]){
            DFS_Mat(x, y - 1);
        }
    }
}*/

int main(){
    IOS
    int n;
    cin>>n;
    rep(i, 0, n - 1){
        int x, y;
        cin>>x>>y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    DFS(1);
    cout<<(dp[1][0] + dp[1][1]) % mod;
    return 0;
}