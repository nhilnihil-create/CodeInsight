#include <bits/stdc++.h>
using namespace std;

int n;

typedef long long ll;
typedef pair<ll, int> pi;

map<ll, int> mp;
const int maxn = 1e5 + 5;
int sz[maxn];
ll d[maxn];
ll dp[maxn];
ll dp1[maxn];
vector<int> G[maxn];

void dfs(int u){
    sz[u] = 1;
    for(auto v : G[u]){
        dfs(v);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}

void dfs1(int u){
    ll sum = 0;
    ll sum1 = 0;
    for(auto v : G[u]){
        sum += dp[v];
        sum1 += sz[v];
    }
    for(auto v : G[u]){
        dp1[v] = dp1[u] + sum - dp[v] + sum1 - sz[v] + n - sz[v];
    }
    for(auto v : G[u]){
        dfs1(v);
    }
}

bool check(int root){
    dfs(root);
    dfs1(root);
    for(int i = 1;i <= n;i++){
        if(dp[i] + dp1[i] != d[i])
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    priority_queue<pi> pq;
    for(int i = 1;i <= n;i++){
        cin >> d[i];
        mp[d[i]] = i;
        pq.push({d[i], i});
        sz[i] = 1;
    }
    bool flag = true;
    int root = 0;
    while(!pq.empty()){
        pi p = pq.top(); pq.pop();
        ll dis = p.first;
        int id = p.second;
        if(sz[id] == n){
            root = id;
            break;
        }
        ll dis1 = dis - (n - 2 * sz[id]);
        if(mp.find(dis1) == mp.end()){
            flag = false;
            break;
        }else{
            int fa = mp[dis1];
            if(fa == id){
                flag = false;
                break;
            }
            G[fa].push_back(id);
            sz[fa] += sz[id];
        }
    }
    if(flag){
        flag &= check(root);
    }
    if(flag){
        for(int i = 1;i <= n;i++){
            for(auto v : G[i]){
                cout << i << " " << v << endl;
            }
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}
