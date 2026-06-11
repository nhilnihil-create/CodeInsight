#include <bits/stdc++.h>
using namespace std;
using ll   = long long;
const ll mod = 1e9+7;

void dfs(vector<vector<int>>& adj, int src, vector<bool>& vis, stack<int>& st){
    vis[src]=true;
    for(auto j:adj[src]){
        if(!vis[j])dfs(adj, j, vis, st);
    }
    st.push(src);
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> in(n,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x-1].push_back(y-1);
        in[y-1]++;
    }
    queue<int> st;
    vector<int> dist(n, -mod);
    for(int i=0;i<n;i++){
        if(in[i]==0){
            st.push(i);
            dist[i]=0;
        }
    }
    while(!st.empty()){
        int src = st.front();st.pop();
        for(auto j:adj[src]){
            if(dist[j]< dist[src]+1){
                dist[j]=dist[src]+1;
            }
            in[j]--;
            if(in[j]==0){
                st.push(j);
            }
        }
    }
    cout<<*max_element(dist.begin(), dist.end());
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r",stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    t=1;
    // cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
